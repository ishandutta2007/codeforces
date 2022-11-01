#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

struct cvor
{
	cvor *djeca[2];
	cvor()
	{
		djeca[0] = NULL;
		djeca[1] = NULL;
	}
} root;

int n;

void ubaci(int sta, int kolko, cvor *tr)
{
	if(kolko < 0) return;
	if(sta & (1 << kolko))
	{
		if(tr -> djeca[1] != NULL) ubaci(sta, kolko - 1, tr -> djeca[1]);
		else
		{
			tr -> djeca[1] = new cvor();
			ubaci(sta, kolko - 1, tr -> djeca[1]);
		}
	}
	else
	{
		if(tr -> djeca[0] != NULL) ubaci(sta, kolko - 1, tr -> djeca[0]);
		else
		{
			tr -> djeca[0] = new cvor();
			ubaci(sta, kolko - 1, tr -> djeca[0]);
		}
	}
	return;
}

int rek(int dub, cvor *tr)
{
	if(dub == 30) return 0;
	if(tr -> djeca[0] != NULL && tr -> djeca[1] != NULL)
	{
		return min(rek(dub + 1, tr -> djeca[0]), rek(dub + 1, tr -> djeca[1])) + (1 << (29 - dub));
	}
	if(tr -> djeca[0] != NULL) return rek(dub + 1, tr -> djeca[0]);
	else return rek(dub + 1, tr -> djeca[1]);
}

int main()
{
	cin >> n;
	int x;
	REP(i, 0, n)
	{
		scanf("%d", &x);
		ubaci(x, 29, &root);
	}
	cout << rek(0, &root) << endl;
	return 0;
}
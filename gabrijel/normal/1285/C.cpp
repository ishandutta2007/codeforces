#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const long long int inf = 1e18;

long long int x, cpx;

vector <long long int> prosti;

int n;

long long int rja = inf, rjb = inf;

void rek(int koji, long long int a, long long int b)
{
	if(koji == n)
	{
		if(max(a, b) < max(rja, rjb))
		{
			rja = a;
			rjb = b;
		}
		return;
	}
	rek(koji + 1, a * prosti[koji], b);
	rek(koji + 1, a, b * prosti[koji]);
	return;
}

int main()
{
	cin >> x;
	cpx = x;
	int br;
	long long int tr;
	REP(i, 2, (int)sqrt(x) + 1)
	{
		if(cpx % i == 0)
		{
			br = 0;
			tr = 1;
			while(cpx % i == 0)
			{
				br++;
				cpx /= i;
				tr = tr * i;
			}
			prosti.push_back(tr);
		}
	}
	if(cpx > 1) prosti.push_back(cpx);
	n = (int)prosti.size();
	rek(0, 1LL, 1LL);
	printf("%lld %lld", rja, rjb);
	return 0;
}
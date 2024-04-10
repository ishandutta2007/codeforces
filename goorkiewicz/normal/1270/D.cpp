#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

const int N = 505;
int n, k, i, j, out;
int t [N];
set <int> S1, S3, S4;
vector <int> S2;
pair <int,int> p;

pair <int,int> Q (const set <int>& S)
	{
	printf ("? ");
	for (int a : S)
		printf ("%d ", a);
	printf ("\n");
	fflush(stdout);
	int res1, res2;
	scanf ("%d %d", &res1, &res2);
	return {res1, res2};
	}

int main ()
	{
	scanf ("%d%d", &n, &k);

	for (i=1; i<=k; i++)
		S1.insert(i);
	for (i=k+1; i<=n; i++)
		S2.push_back(i);
	
	while (true)
		{
		p = Q(S1);
		t[p.f] = p.s;
		S1.erase(p.f);
		S3.insert(p.f);
		if (S2.empty())
			break;
		S1.insert(S2.back());
		S2.pop_back();
		}
	
	j = 0;
	for (int a : S3)
		if (j==0 || t[a]<t[j])
			j = a;
	
	S1.insert(j);
	S3.erase(j);
	assert(S1.size() == k);
	assert(S3.size() == n-k);

	k = (*S3.begin());
	
	S4 = S1;
	for (int a : S1)
		{
		if (a==j)
			continue;
		S4.erase(a);
		S4.insert(k);
		p = Q(S4);
		if (p.f != j)
			out++;
		S4.insert(a);
		S4.erase(k);
		}
	
	printf ("! %d\n", out+1);
	fflush(stdout);
	
	return 0;
	}
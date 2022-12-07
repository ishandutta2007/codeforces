#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, i, j, k, x;
ll out;
int sieve [N];
map <int,int> R, P;
map < map <int,int> , int > M;

int main ()
	{
	for (i=2; i<N; i++)
		if (sieve[i]==0)
			for (j=i; j<N; j+=i)
				sieve[j] = i;
	
	scanf ("%d%d",&n,&k);
	for (i=1; i<=n; i++)
		{
		scanf ("%d",&x);
		R.clear();
		while (x!=1)
			{
			if (++R[sieve[x]]==k)
				R.erase(sieve[x]);
			x /= sieve[x];
			}
		
		P.clear();
		for (pair <int,int> p : R)
			P[p.first] = k-p.second;
		
		out += M[P];
		M[R]++;
		}
	
	printf ("%lld\n", out);
	return 0;
	}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 3001;
int n, m, w, i, j;
bool sieve [M];
bool b [M];
vector < pair <int,int> > out;

int main ()
	{
	sieve[0] = true;
	sieve[1] = true;
	for (i=2; i<=M; i++)
		if (sieve[i]==false)
			for (j=i+i; j<=M; j+=i)
				sieve[j] = true;
	
	scanf ("%d",&n);
	m = n;
	w = m;
	while (sieve[w]==true)
		w++;
	
	out.push_back({n,1});
	for (i=1; i<n; i++)
		out.push_back({i,i+1});
	
	w-=m;
	i = 1;
	for (i=1; i<=n && w!=0; i++)
		{
		if (b[i]==false)
			{
			out.push_back({i,i+2});
			b[i] = true;
			b[i+2] = true;
			w--;
			}
		}
	
	printf ("%d\n",out.size());
	for (auto p : out)
		printf ("%d %d\n",p.first,p.second);
	
	return 0;
	}
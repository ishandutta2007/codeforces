#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000005;
int p [N];
ll n, i, j, d, out;
vector <ll> fact;

int Find(int x)
	{
	if (x==p[x])
		return x;
	p[x] = Find(p[x]);
	return p[x];
	}

void Union (int a, int b)
	{
	a = Find(a);
	b = Find(b);
	if (a==b) return;
	p[a] = b;
	}

int main ()
	{
	scanf("%lld", &n);
	
	if (n==1)
		return printf("1\n"), 0;
	
	for (d=2; d*d<=n; d++)
		if (n%d==0)
			{
			fact.push_back(d);
			while(n%d==0)
				n/=d;
			}
	
	if (n!=1)
		fact.push_back(n);
	
	if (fact.size()==1)
		return printf("%lld\n", fact[0]), 0;
	
	d = fact[0];
	for(i=1; i<=d; i++)
		p[i] = i;
	
	for (i=1; i<=d; i++)
		for (ll f : fact)
			{
			if (f==d) continue;
			ll j = (i+f)%d;
			if (j==0) j+=d;
			Union(i, j);
			}
	
	for (i=1; i<=d; i++)
		if (Find(i)==i)
			out++;
	
	printf("%lld\n", out);
	return 0;
	}
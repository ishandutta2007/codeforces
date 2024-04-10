#include <iostream>
#include <cstdio>

#include <set>
#include <vector>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int MN = 1e5 + 100;
const int ML = 1e3 + 100;
const int MV = 1e9 + 100;
const int MLV = 1e4 + 100;

int val(int n)
{
	int r=1;
	for(int t;n;n/=10)
		if((t=n%10)!=7&&t!=4)
			return 0;
		else
			r=r<<1|t==7;
	return r;
}
ll pc[MN];
ll c2(ll v)	//***not actually choose 2***
{
	return v*(v+1)>>1;
}
void pcppc(void)
{
	for(int i = 0;i < MN-1;i++)
		pc[i+1] = pc[i] + c2(tl(i));
}
int N, L;
ll f;
int a[MN];
using vi = vector<int>;
#define pb push_back
int w[ML], v[ML];
vi p[MLV];
bool u[MLV];
using si = set<int>;
#define IT iterator
using sit = si::IT;
void count(int x)
{
	si s;s.clear();
	ll c = 0LL;
	ll e = w[x]-w[x-1];
	s.insert(0);
	auto cur = [&] (void) -> ll
	{
		int t=*s.rbegin();
		return (pc[w[x]-w[t]]-pc[w[x-1]-w[t]]) + c*e;
	};
	auto ins = [&] (int k)
	{
		sit n = s.insert(k).first, p=n++;
		p--;
		if(n==s.end())
			c += c2(w[k]-w[*p]-1);
		else
			c -= (w[*n]-w[k])*(w[k]-w[*p]);
	};
	auto insa = [&] (int k)
	{
		for(int y : p[k])
			if(y < x)
				ins(y);
			else
				break;
	};
	for(int i = x;i <= L;i++)
	{
		if(!u[v[i]])
			insa(v[i]), u[v[i]] = 1;
		f += cur()*(w[i+1]-w[i]);
	}
	for(int i = x;i <= L;i++)
		u[v[i]] = 0;
}
int main(void)
{
	pcppc();
	scanf("%d", &N);
	w[0] = -1;
	for(int i = 0, j;i < N;i++)
	{
		scanf("%d", a + i);
		j=val(a[i]);
		if(j)
			v[++L] = j, w[L] = i, p[j].pb(L);
	}
	w[L+1] = N;
	for(int i = 1;i <= L;i++)
		count(i);
	//printf("%lld\n", f);
	for(int i = 0;i <= L;i++)
		for(int j = w[i]+1;j < w[i+1];j++)
			f += c2(j)*(w[i+1]-j);
	printf("%lld\n", f);
	return 0;
}
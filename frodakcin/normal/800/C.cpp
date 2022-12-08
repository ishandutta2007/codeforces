#include <iostream>
#include <cstdio>

#include <vector>
#include <bitset>

#include <cassert>

using namespace std;

template<class T> bool mx(T& a, const T& b){return a<b?a=b,1:0;}
template<int T> using bs = bitset<T>;
const int MM = 2e5 + 100;
const int MP = 5e4 + 100;
const int MN = MM;
using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
int P[MP];
bs<MM> p;
int c[MM], d[MM], n[MM];
void pcpp(void)
{
	p.reset();
	P[0] = 0;
	for(int i = 2;i < MM;i++)
	{
		if(!p[i]) P[++P[0]] = i, c[i] = 1, n[i] = 1, d[i] = i;
		for(int j = 1, k;j <= P[0]&&(k=i*P[j]) < MM;j++)
		{
			p[k] = 1, d[k] = P[j];
			if(P[j]==d[i])
			{
				n[k] = n[i], c[k] = c[i]+1;
				break;
			}
			else
				n[k] = i, c[k] = 1;
		}
	}
}
int tot(int x)
{
	ll f = x;
	for(;x!=1;x=n[x])
		f = f*(d[x]-1)/d[x];
	return ti(f);
}
int N, M, T;
int pw(ll b, ll p, int m)
{
	ll r = 1LL;
	for(;p;p>>=1LL,b=b*b%m) if(p&1) r=r*b%m;
	return ti(r);
}
int gcd(int a, int b)
{
	if(!a) return b;
	return gcd(b%a, a);
}
int v[MM], u[MM];
int a[MN];
bs<MM> w;
using vi = vector<int>;
#define pb push_back
vi b[MN];
int to(int a, int b, int c, int d)		//a*b -> c*d, d divides b, a c rel prime to M
{
	//assert(d%b==0);
	int m = M/b;
	return ti(pw(a, tot(m)-1, m)*tl(c)%M*(d/b)%M);
}
int main(void)
{
	pcpp();
	scanf("%d%d", &N, &M);
	T = tot(M);
	for(int i = 0;i < N;i++)
		scanf("%d", a + i), w[a[i]] = 1;
	for(int i = 0, j;i < M;i++)
		if(!w[i])
			j = gcd(i, M), v[j]++, b[j].pb(i);
	for(int i = M-1;i > 0;i--)
	{
		if(M%i)
			continue;
		int x = -1;
		for(int j = M;j != 1;j=n[j])
		{
			if(!(M%(i*d[j])))
				if(mx(x, v[i*d[j]]))
					u[i] = i*d[j];
		}
		v[i] += x;
	}
	printf("%d\n", v[1]);
	for(int i = 1, j = -1, k = -1, x;;i=u[i])
	{
		x = gcd(i, M);
		//assert(x==i);
		if(!b[i].empty())
		{
			if(j!=-1)
				printf(" %d", to(j, k, b[i].front()/x, x));
			else
				printf("%d", b[i].front());
		}
		for(int l = 1;l < b[i].size();l++)
		{
			printf(" %d", to(b[i][l-1]/x, x, b[i][l]/x, x));
		}
		if(!b[i].empty())
			j = b[i].back()/x, k = x;
		if(i==M) break;
	}
	printf("\n");
	return 0;
}
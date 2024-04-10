#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
const int LG=100;

ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}
inline void chk_max(ll &a,ll b){ if(a<b) a=b;}
inline void chk_min(ll &a,ll b){ if(a>b) a=b;}

struct Node
{
	ll x;
	int cnt;
}d[LG];
int tot=0;

void gao(ll a)
{
	int sa = sqrt(a);
	for(int i=2; i<=sa && a>1; ++i)
		if(a%i==0)
		{
			int cnt=0;
			while(a%i==0) a/=i, ++cnt;
			d[++tot] = (Node){i,cnt};
		}
	if(a>1) d[++tot] = (Node){a,1};
}

ll g(ll a,ll b)
{
	if(!b) return 0;
	ll t=gcd(a,b);
	a/=t; b/=t;
	return g(a,b-1)+1;
}

ll f(ll a,ll b)
{
	if(!b) return 0;
	ll t=gcd(a,b);
	a/=t; b/=t;
	
	for(int i=1; i<=tot; ++i)
		while(d[i].cnt && t%d[i].x==0)
			--d[i].cnt, t/=d[i].x;
	
	ll mn=b;
	for(int i=1; i<=tot; ++i)
		if(d[i].cnt) chk_min(mn, b%d[i].x);
	
	return f(a,b-mn)+mn;
}

int main(void)
{
	ll a,b;
	cin>>a>>b;
	gao(a);
	cout<<f(a,b);
	return 0;
}
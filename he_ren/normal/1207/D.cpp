#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXN = 3e5 + 5;
const int mod = 998244353;
using namespace std;

struct Node
{
	int a,b;
}s[MAXN];
inline bool cmp1(Node x,Node y){ return x.a<y.a;}
inline bool cmp2(Node x,Node y){ return x.b!=y.b? x.b<y.b: x.a<y.a;}

ll fac[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i] = fac[i-1]*i %mod;
	
	for(int i=1; i<=n; ++i) scanf("%d%d",&s[i].a,&s[i].b);
	
	ll ans1=1;
	sort(s+1,s+n+1,cmp1);
	for(int i=1; i<=n;)
	{
		int tmp=i;
		while(s[tmp].a==s[i].a && i<=n) ++i;
		ans1 = (ans1*fac[i-tmp])%mod;
	}
	
	sort(s+1,s+n+1,cmp2);
	ll ans2=1;
	for(int i=1; i<=n;)
	{
		int tmp=i;
		while(s[tmp].b==s[i].b && i<=n) ++i;
		ans2 = (ans2*fac[i-tmp])%mod;
	}
	
	ll ans3=0;
	bool flag=1;
	for(int i=1; i<n; ++i)
		if(s[i].a>s[i+1].a)
		{
			flag=0;
			break;
		}
	
	if(flag)
	{
		ans3=1;
		for(int i=1; i<=n;)
		{
			int tmp=i;
			while(s[tmp].a==s[i].a && s[tmp].b==s[i].b && i<=n) ++i;
			ans3 = (ans3*fac[i-tmp])%mod;
		}
	}
	
	cout<<((fac[n]-ans1-ans2+ans3)%mod + mod) %mod;
	return 0;
}
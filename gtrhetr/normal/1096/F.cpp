#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL
#define lowbit(x) ((x)&(-(x)))

ll ans;
int sum[200010],num[200010],c[200010],n; 
bool bo[200010];

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void add(int x) { for (;x;x-=lowbit(x)) c[x]++; }

inline int query(int x)
{
	int res=0;
	for (;x<=n;x+=lowbit(x)) res+=c[x];
	return res;
}

inline ll calc(ll x) { return x*(x+1)/2%mod; }

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) if (num[i]!=-1) bo[num[i]]=true;
	int tt=0;
	for (int i=1;i<=n;i++) if (num[i]==-1) tt++;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(!bo[i]);
	ans=0;
	int now=0;
	ll Inv=ksm(tt,mod-2)%mod;
	for (int i=1;i<=n;i++)
	{
		if (~num[i])
		{
			ans=pls(ans,mns(tt,now)*Inv%mod*sum[num[i]]%mod);
			ans=pls(ans,now*Inv%mod*(tt-sum[num[i]])%mod);
			ans=pls(ans,query(num[i]));
			add(num[i]-1);
		}
		else now++;
	}
	for (int i=2;i<=tt;i++) ans=pls(ans,ksm(i,mod-2)*calc(i-1)%mod);
	printf("%lld\n",ans);
	return 0;
}
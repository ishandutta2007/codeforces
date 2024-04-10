#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))

pii h[200010];

int c[200010];
int cnt[1010],num[200010],n;
ll cnt1[1010],m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x) { for (;x;x-=lowbit(x)) c[x]++; }

inline int sum(int x)
{
	int res=0;
	for (;x<=m;x+=lowbit(x)) res+=c[x];
	return res;
}

inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%m) if (y&1) res=res*x%m;return res; }

int main()
{
	n=rd();m=rd();
	if (m==1) { puts("0");return 0; }
	for (int i=1;i<=n;i++) num[i]=rd(),cnt[num[i]%m]++;
	for (int i=0;i<m;i++) if (cnt[i]>1) { puts("0");return 0; }
	ll ans=1;
	for (int i=1;i<n;i++) for (int j=i+1;j<=n;j++) ans=ans*abs(num[i]-num[j])%m;
	printf("%lld\n",ans);
	return 0;
}
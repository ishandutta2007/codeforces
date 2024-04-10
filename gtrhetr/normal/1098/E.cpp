#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

pii h[100010],h1[100010];

ll cnt[100010],pre[100010],sum[100010];
int num[100010],mx[100010],n,tt,t1;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int gcd(int x,int y) { return (!y)?x:gcd(y,x%y); }

inline ll calc(ll l,ll r) { return (l+r)*(r-l+1)/2; }

inline ll anol_gcd(ll n,ll a,ll b,ll c)
{
	if (n<0) return 0;
	if (!a) return (b/c)*(n+1);
	if (a>=c||b>=c) return (a/c)*n*(n+1)/2+(b/c)*(n+1)+anol_gcd(n,a%c,b%c,c);
	ll hh=(a*n+b)/c;
	return n*hh-anol_gcd(hh-1,c,c-b-1,a);
}

inline ll gao(int x,int y,ll mid)
{
	if (!cnt[x]||!cnt[y]) return 0;
	mid-=pre[y-1]-pre[x];
	if (mid<0) return 0;
	ll mn=(mid-cnt[y]*y)/x;
	mn=max(mn,0LL);
	if (mn>=cnt[x]) return cnt[x]*cnt[y];
	ll res=mn*cnt[y];mn++;
	ll mx=mid/x;
	mx=min(mx,cnt[x]);
	if (mn<=mx) res+=anol_gcd(mx-mn,x,mid-mx*x,y);
	return res;
}

inline ll check(ll mid)
{
	ll res=0;
	int now=1;
	for (int i=1;i<=100000;i++)
	{
		now=max(now,i);
		ll hh=min(mid/i,cnt[i]);
		if (cnt[i]) res+=calc(cnt[i]-hh+1,cnt[i]);
		while (now+1<=100000&&pre[now+1]-pre[i-1]<=mid) now++;
		res+=(sum[now]-sum[i])*cnt[i];
		mx[i]=now;
	}
	for (int i=1;i<=100000;i++) for (int j=mx[i]+1;j<=min(mx[i+1]+1,100000);j++) res+=gao(i,j,mid);
	return res;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	cnt[num[1]]++;
	h[tt=1]=pii(1,num[1]);
	for (int i=2;i<=n;i++)
	{
		t1=tt;
		for (int j=1;j<=t1;j++) h1[j]=h[j],h1[j].second=gcd(h1[j].second,num[i]);
		h1[++t1]=pii(1,num[i]);
		tt=0;
		for (int j=1;j<=t1;)
		{
			int k=j,now=0;
			for (;k<=t1&&h1[k].second==h1[j].second;k++) now+=h1[k].first;
			h[++tt]=pii(now,h1[j].second);j=k;
		}
		for (int j=1;j<=tt;j++) cnt[h[j].second]+=h[j].first;
	}
	for (int i=1;i<=100000;i++) pre[i]=pre[i-1]+cnt[i]*i,sum[i]=sum[i-1]+cnt[i];
	ll all=(ll)n*(n+1)/2;
	all=all*(all+1)/2;
	all=(all+1)/2;
	ll l=0,r=(ll)n*(n+1)/2*100000;
	while (l<r)
	{
		ll mid=(l+r)>>1;
		if (check(mid)>=all) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}
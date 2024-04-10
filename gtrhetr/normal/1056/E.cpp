#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define mod 998244353LL
#define ull unsigned long long

pii h[1000010];

ll h1[1000010],b[1000010];
ull hs[1000010],bin[1000010];
int n,m,tt;

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }

char s[100010],t[1000010];

inline ull calc(int l,int r) { return hs[r]-hs[l-1]*bin[r-l+1]; }
inline ll c1(int l,int r) { return mns(h1[r],h1[l-1]*b[r-l+1]%mod); }

int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);m=strlen(t+1);
	int ans=0;
	int s0=0,s1=0;
	for (int i=1;i<=n;i++) if (s[i]=='0') s0++;else s1++;
	tt=0;
	if (s0>=s1) { for (int i=1;i*s0<m;i++) if ((m-i*s0)%s1==0) h[++tt]=pii(i,(m-i*s0)/s1); }
	else for (int i=1;i*s1<m;i++) if ((m-i*s1)%s0==0) h[++tt]=pii((m-i*s1)/s0,i);
	bin[0]=1;
	for (int i=1;i<=m;i++) bin[i]=bin[i-1]*233ull;
	for (int i=1;i<=m;i++) hs[i]=hs[i-1]*233ull+(t[i]-'a'+1);
	b[0]=1;
	for (int i=1;i<=m;i++) b[i]=b[i-1]*313%mod;
	for (int i=1;i<=m;i++) h1[i]=pls(h1[i-1]*313%mod,t[i]-'a'+1);
	ll hhh=h1[m];
	for (int i=1;i<=tt;i++)
	{
		ull h1,h2;ll hh1,hh2;
		int now=1;
		for (int j=1;j<=n;j++)
		{
			if (s[j]=='0') h1=calc(now,now+h[i].first-1),hh1=c1(now,now+h[i].first-1),now+=h[i].first;
			if (s[j]=='1') h2=calc(now,now+h[i].second-1),hh2=c1(now,now+h[i].second-1),now+=h[i].second;
		}
		if (h1==h2&&hh1==hh2) continue;
		ull res=0;ll res1=0;now=1;
		for (int j=1;j<=n;j++)
		{
			if (s[j]=='0') res+=h1*bin[(m-(now+h[i].first-1))],res1=pls(res1,hh1*b[m-(now+h[i].first-1)]%mod),now+=h[i].first;
			else res+=h2*bin[m-(now+h[i].second-1)],res1=pls(res1,hh2*b[m-(now+h[i].second-1)]%mod),now+=h[i].second;
		}
		if (res==hs[m]&&(res1==hhh)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
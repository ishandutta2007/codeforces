#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>

unordered_map<ll,int> mp;

pll ans[16];

pll num[131072][16],from[16];

ll cnt[20],h[20][5010],s[20],n;
bool vis[20],bo[1048576],f[1048576];

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void pre_gao()
{
	int now=0;
	for (int i=1;i<=n;i++) if (vis[i]) now|=(1<<(i-1));
	bo[now]=true;
	for (int i=1;i<=n;i++) num[now][i]=from[i];
}

inline void gao(int id)
{
	for (int i=1;i<=n;i++) if ((1<<(i-1))&id) ans[num[id][i].second]=pll(num[id][i].first,i);
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++)
	{
		cnt[i]=rd();
		for (int j=1;j<=cnt[i];j++) h[i][j]=rd(),mp[h[i][j]]=i;
		sort(h[i]+1,h[i]+cnt[i]+1);
		s[i]=0;
		for (int j=1;j<=cnt[i];j++) s[i]+=h[i][j];
	}
	ll sum=0;
	for (int i=1;i<=n;i++) for (int j=1;j<=cnt[i];j++) sum+=h[i][j];
	if (sum%n) { puts("No");return 0; }
	ll all=sum/n;
	for (int i=1;i<=n;i++) for (int j=1;j<=cnt[i];j++)
	{
		memset(vis,false,sizeof(vis));
		vis[i]=true;
		int now=h[i][j],hh=i;
		bool flag=true;
		while (233)
		{
			int to=mp[now+(all-s[hh])];
			if (!vis[to]) { vis[to]=true;from[hh]=pll(now+all-s[hh],to);now=now+all-s[hh];hh=to;continue; }
			else if (to!=i) { flag=false;break; }
			else if (now+all-s[hh]!=h[i][j]) { flag=false;break; }
			else { from[hh]=pll(now+all-s[hh],to);break; }
		}
		if (!flag) continue;
		pre_gao();
	}
	f[0]=1;
	for (int i=1;i<(1<<n);i++) for (int j=i;j;j=(j-1)&i) f[i]|=(f[i^j]&bo[j]);
	if (!f[(1<<n)-1]) { puts("No");return 0; }
	puts("Yes");
	int now=(1<<n)-1;
	while (now)
	{
		int id=0;
		for (int j=now;j;j=(j-1)&now) if (bo[j]&&f[now^j]) { id=j;break; }
		now^=id;gao(id);
	}
	for (int i=1;i<=n;i++) printf("%lld %lld\n",ans[i].first,ans[i].second);
	return 0;
}
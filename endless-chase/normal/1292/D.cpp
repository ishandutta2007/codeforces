#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=5000,mod1=998244353,mod2=1e9+7,p=131;
int n,prime[5555],mx[5555],pnt[5555][1111],cnt,a[1111111],re[55555],cn,all[5555],call,mk1,mk2,cr[1111];
bool f[5555];
int dep[55555],pa[55555],pl[55555],sub[55555],mxx,pw1[1111],pw2[1111];
int rig[55555],crr;
int fucked[5555];
long long dis,ans;
vector<pair<int,int> > g[55555];
map<pair<int,int>,int> mp;
int getn(int mod1,int mod2)
{
	if (mp.find(make_pair(mod1,mod2))==mp.end()) mp[make_pair(mod1,mod2)]=++cn;
	return mp[make_pair(mod1,mod2)];
}
void Init()
{
	for (int i=2;i<=maxn;i++)
	{
		if (!f[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt && i*prime[j]<=maxn;j++)
		{
			f[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		for (int j=prime[i];j<=maxn;j+=prime[i])
		{
			mx[j]=i;
		}
	}
	for (int i=1;i<=maxn;i++)
	{
		for (int j=1;j<=cnt;j++) 
		{
			pnt[i][j]=pnt[i-1][j];
		}
		int tt=i;
		while(tt>1)
		{
			pnt[i][mx[tt]]++;
			tt/=prime[mx[tt]];
		}
		for (int j=1;j<=cnt;j++) all[i]+=pnt[i][j];
	}
}
void dfs(int i,int dp)
{
	if (re[i]!=-1) 
	{
		dis+=(1ll*dp*fucked[re[i]]);
		sub[i]=fucked[re[i]];
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		dfs(to,dp+val);
		sub[i]+=sub[to];
	}
}
void dft(int i)
{
	ans=min(ans,dis);
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		dis+=(1ll*(n-sub[to])*val);dis-=(1ll*sub[to]*val);
		dft(to);
		dis-=(1ll*(n-sub[to])*val);dis+=(1ll*sub[to]*val);
	}
}
void add(int i,int f)
{
	if (i!=f) 
	{
		pa[i]=f;
		pl[i]=dep[i]-dep[f];
	}
}
int main()
{
	Init();
	pw1[0]=pw2[0]=1;
	for (int i=1;i<=cnt;i++)
	{
		pw1[i]=1ll*pw1[i-1]*p%mod1;
		pw2[i]=1ll*pw2[i-1]*p%mod2;
	}
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==0) a[i]=1;
		fucked[a[i]]++;
		mxx=max(mxx,a[i]);
	}
	memset(re,-1,sizeof(re));
	crr=1;rig[1]=1;cn=1;dep[1]=0;mp[make_pair(0,0)]=1;re[1]=1;
	for (int i=2;i<=mxx;i++)
	{
		mk1=mk2=0;int pos=-1;call=0;
		for (int j=cnt;j>=1;j--)
		{
			if (cr[j]==pnt[i][j]) 
			{
				mk1=(1ll*cr[j]*pw1[j-1]+mk1)%mod1;
				mk2=(1ll*cr[j]*pw1[j-1]+mk2)%mod2;
				call+=cr[j];
			}
			else
			{
				pos=j;
				mk1=(1ll*cr[j]*pw1[j-1]+mk1)%mod1;
				mk2=(1ll*cr[j]*pw1[j-1]+mk2)%mod2;
				call+=cr[j];
				break;
			}
		}
		for (int j=1;j<=cnt;j++) cr[j]=pnt[i][j];
		int idd=getn(mk1,mk2);
		dep[idd]=call;bool flg=0;
		for (int j=1;j<crr;j++)
		{
			if (dep[idd]>=dep[rig[j]] && dep[idd]<=dep[rig[j+1]]) 
			{
				crr=j;add(idd,rig[j]);add(rig[j+1],idd);
				flg=1;
				break;
			}
		}
		if (!flg)
		{
			add(idd,rig[crr]);
		}
		rig[++crr]=idd;rig[++crr]=++cn;dep[cn]=all[i];
		re[cn]=i;add(cn,idd);
		mk1=0;mk2=0;
		for (int j=1;j<=cnt;j++)
		{
			mk1=(1ll*pnt[i][j]*pw1[j-1]+mk1)%mod1;
			mk2=(1ll*pnt[i][j]*pw1[j-1]+mk2)%mod2;
		}
		mp[make_pair(mk1,mk2)]=cn;
	}
	for (int i=1;i<=cn;i++)
	{
		if (pa[i]) g[pa[i]].push_back(make_pair(i,pl[i]));
	}
	dfs(1,0);
	ans=dis;
	dft(1);
	printf("%lld\n",ans);
	return Accepted;
}
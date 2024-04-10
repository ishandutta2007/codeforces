#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
#define bs bitset<128>
#define lowbit(x) ((x)&(-(x)))

unordered_map<bs,int> f,g;
unordered_map<bs,int> id;

bs f1[70010][128];

ll p[10][10];
int n,tt=0;
bool bo[10];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int pls(const int &x,const int &y) { return (x+y<mod)?x+y:x+y-mod; }
inline int mns(const int &x,const int &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void gao(bs hh)
{
	id[hh]=++tt;
	for (int i=1;i<=n;i++)
	{
		f1[tt][1<<(i-1)]=hh;
		for (int j=0;j<(1<<n);j++) if (hh[j]&&!((j>>(i-1))&1)) f1[tt][1<<(i-1)][j|(1<<(i-1))]=1;
	}
	for (int i=1;i<(1<<n);i++) if (!f1[tt][i].count()) f1[tt][i]=f1[tt][lowbit(i)]|f1[tt][i^lowbit(i)];
}

int main()
{
	n=rd();
	ll Inv=ksm(100,mod-2);
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) p[i][j]=rd()*Inv%mod;
	f[1]=1;
	for (int i=1;i<=n;i++)
	{
		g=f;f.clear();
		for (unordered_map<bs,int>::iterator it=g.begin();it!=g.end();it++) if (!id[it->first]) gao(it->first);
		for (int j=1;j<(1<<n);j++)
		{
			ll now=1;
			for (int k=1;k<=n;k++)
			{
				bo[k]=((j>>(k-1))&1);
				if (bo[k]) now=now*p[k][i]%mod;
				else now=now*mns(1,p[k][i])%mod;
			}
			for (unordered_map<bs,int>::iterator it=g.begin();it!=g.end();it++)
			{
				bs hh=it->first;
				f[f1[id[hh]][j]]=pls(f[f1[id[hh]][j]],(ll)it->second*now%mod);
			}
		}
	}
	int ans=0;
	for (unordered_map<bs,int>::iterator it=f.begin();it!=f.end();it++) if ((it->first).test((1<<n)-1)) ans=pls(ans,it->second);
	printf("%d\n",ans);
	return 0;
}
/*
7
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
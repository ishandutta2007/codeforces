//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
typedef unsigned long long ull;
char s[500111];
int n;
pair<ull,ull> pw[500111],sum[500111],hs[500111];
pair<ull,ull> geths(int x,int y)
{
	return MP(sum[y].FF-sum[x-1].FF*pw[y-x+1].FF,sum[y].SS-sum[x-1].SS*pw[y-x+1].SS);
}
int st[500111],stsz;
bool sb[500111];
ll ans;
struct suffix_array
{
	int n,s[500111],pre[500111];
	int sa[500111],b[500111],tmp[500111],rk[500111],nrk[500111];
	void init()
	{
		n=0;
	}
	void add(int t)
	{
		s[++n]=t;
	}
	bool cmp(int x,int y,int i)
	{
		if(rk[x]!=rk[y])return rk[x]>rk[y];
		else
		{
			int tx=x+i>pre[x]?0:rk[x+i];
			int ty=y+i>pre[y]?0:rk[y+i];
			return tx>ty;
		}
	}
	void construct_sa()
	{
		for(int i=0;i<=n;i++)b[i]=0;
		for(int i=1;i<=n;i++)b[s[i]]++;
		for(int i=1;i<=n;i++)b[i]+=b[i-1];
		for(int i=n;i>=1;i--)rk[i]=b[s[i]];
		for(int i=n;i>=1;i--)sa[b[s[i]]--]=i;
		for(int i=1;i<=n;i*=2)
		{
			for(int j=0;j<=n;j++)b[j]=0;
			for(int j=1;j<=n;j++)b[rk[j]]++;
			for(int j=2;j<=n;j++)b[j]+=b[j-1];
			int id=0;
			for(int j=1;j<=n;j++)if(sa[j]>pre[sa[j]]-i)tmp[++id]=sa[j];
			for(int j=1;j<=n;j++)if(sa[j]>i&&pre[sa[j]-i]==pre[sa[j]])tmp[++id]=sa[j]-i;
			for(int j=n;j>=1;j--)sa[b[rk[tmp[j]]]--]=tmp[j];
			nrk[sa[1]]=1;
			for(int j=2;j<=n;j++)nrk[sa[j]]=nrk[sa[j-1]]+cmp(sa[j],sa[j-1],i);
			for(int j=1;j<=n;j++)rk[j]=nrk[j];
		}
		for(int i=1;i<=n;i++)rk[sa[i]]=i;
		int h=0;
		for(int i=1;i<=n;i++)
		{
			if(rk[i]==1)
			{
				ans+=pre[i]-i+1;
				continue;
			}
			int j=sa[rk[i]-1];
			if(h>0)h--;
			for(;i+h<=pre[i]&&j+h<=pre[j]&&s[i+h]==s[j+h];h++);
			ans+=max(pre[i]-i+1-min(pre[j]-j+1,h),0);
//			cout<<i<<" "<<pre[i]<<" "<<h<<" "<<j<<" "<<pre[j]<<endl;
		}
	}
}sa;
int idtot;
map<pair<ull,ull>,int> id;
int nxt[500111];
void calc(int x,int y)
{
//	cout<<"calc:"<<x<<","<<y<<endl;
	int prev=sa.n;
	for(int i=x;i<=y;i=nxt[i]+1)
	{
		if(sb[i])
		{
			for(int j=prev+1;j<=sa.n;j++)sa.pre[j]=sa.n;
			prev=sa.n;
			continue;
		}
//		cout<<hs[i].FF<<" "<<hs[i].SS<<endl;
		int &v=id[hs[i]];
		if(v==0)v=++idtot;
		sa.add(v);
	}
	for(int j=prev+1;j<=sa.n;j++)sa.pre[j]=sa.n;
}
int main()
{
	pw[0]=MP(1,1);
	for(int i=1;i<=500005;i++)pw[i]=MP(pw[i-1].FF*1221,pw[i-1].SS*12221);
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		nxt[i]=i;
		sum[i]=MP(sum[i-1].FF*1221+s[i],sum[i-1].SS*12221+s[i]);
	}
	memset(sb,-1,sizeof(sb));
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')st[stsz++]=i;
		else
		{
			if(stsz>0)
			{
				int x=st[stsz-1];
				stsz--;
				nxt[x]=i;
				hs[x]=geths(x,i);
				sb[i]=sb[x]=0;
				calc(x+1,i-1);
			}
		}
	}
	calc(1,n);
	sa.construct_sa();
	cout<<ans<<endl;
	return 0;
}
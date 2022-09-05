//by yjz
#include<bits/stdc++.h>
using namespace std;
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
int n;
ll ans,mod,phi;
ll kissme(ll x,ll k)
{
	ll ret=1;
	while(k>0)
	{
		if(k&1)ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}
vector<pair<int,int> > con[100111];
bool sep[100111];
int sz[100111];
vector<int>v;
void initsz(int x,int pre)
{
	sz[x]=0;
	if(sep[x])return;
	v.PB(x);
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i].FF==pre)continue;
		initsz(con[x][i].FF,x);
		sz[x]+=sz[con[x][i].FF];
	}
	sz[x]++;
}
map<ll,int>mp;
void add(int x,int pre,ll val,ll bs=1)
{
	if(sep[x])return;
	mp[val%mod]++;
//	cout<<"add:"<<x<<","<<val%mod<<endl;
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i].FF==pre)continue;
		add(con[x][i].FF,x,(val+bs*10*con[x][i].SS)%mod,bs*10%mod);
	}
}
void query(int x,int pre,ll val,ll bs,bool isadd)
{
	if(sep[x])return;
	val%=mod;
	ll t=(mod-val)*kissme(bs,phi-1)%mod;
	if(isadd&&val==0)ans++;
//	cout<<"query:"<<x<<","<<t<<" val="<<val<<endl;
	if(isadd)ans+=mp[t];else ans-=mp[t];
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i].FF==pre)continue;
		query(con[x][i].FF,x,(val*10+con[x][i].SS)%mod,bs*10%mod,isadd);
	}
}
void solve(int x)
{
//	cout<<"s:"<<x<<endl;
	if(sep[x])return;
	v.clear();
	initsz(x,-1);
	int pivot=x;
	for(int i=0;i<v.size();i++)
	{
		int x=v[i];
		if(sz[x]>=v.size()/2&&sz[x]<sz[pivot])pivot=x;
	}
//	cout<<"solve:"<<pivot<<" "<<v.size()<<endl;
//	system("pause");
//	cout<<"solve:"<<x<<" "<<pivot<<endl;
//	system("pause");
//	for(int i=1;i<=n;i++)cout<<sep[i];cout<<endl;
	sep[pivot]=1;
	mp.clear();
	for(int i=0;i<con[pivot].size();i++)
	{
		add(con[pivot][i].FF,pivot,con[pivot][i].SS);
	}
	for(int i=0;i<con[pivot].size();i++)query(con[pivot][i].FF,pivot,con[pivot][i].SS,10,1);
	ans+=mp[0];
//	cout<<"mp[0]="<<mp[0]<<endl;
//	cout<<"---------ans="<<ans<<endl;
	for(int i=0;i<con[pivot].size();i++)
	{
		mp.clear();
		add(con[pivot][i].FF,pivot,con[pivot][i].SS);
		query(con[pivot][i].FF,pivot,con[pivot][i].SS,10,0);
	}
//	cout<<"---------ans="<<ans<<endl;
	for(int i=0;i<con[pivot].size();i++)
	{
		solve(con[pivot][i].FF);
	}
}
int main()
{
	getii(n,mod);
	ll t=mod;
	phi=mod;
	for(int i=2;1ll*i*i<=t;i++)
	{
		if(t%i==0)
		{
			phi=phi/i*(i-1);
			while(t%i==0)t/=i;
		}
	}
	if(t>1)phi=phi/t*(t-1);
//	n=100000;mod=3;
	if(mod==1)
	{
		putsi(1ll*n*(n-1));
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y,d;
		getiii(x,y,d);
//		x=i-1;y=i;d=rand()%9+1;
		x++;y++;
		con[x].PB(MP(y,d));
		con[y].PB(MP(x,d));
	}
	solve(1);
	putsi(ans);
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define LL __int128
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
	ll ksm(ll a,ll b)
	{
		ll ans=1;
		while(b)
		{
			if(b&1)ans*=a,ans%=mod;
			a*=a,a%=mod,b>>=1;
		}
		return ans;
	}
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
	int prim[xx],mn[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
const int xx=5e5+5,mod=998244353;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
int n,m,k,a[xx];
char s[xx];
LL d[105][105],pw[105];
//2 
void in(LL &t)
{
	t=0;
	scanf("%s",s);
	for(int i=0;i<n;i++)
		t+=(s[i]=='1')*pw[i];
}
void ou(LL t)
{
	for(int i=0;i<n;i++)
	cout<<(int)(t>>i&1);
	puts("");
}
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
vector<pair<int,int> >v;
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int cr,dis[105][105],*D;
void dfs(int x,int y,int t)
{
	if(D[x]!=-1){cr=0;return;}
	D[x]=t;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x,t+1);
	}
}
bool check()
{
	if(v.size()!=n-1)return 0;
	memset(h,0,sizeof(h[0])*(n+1));
	memset(dis,-1,sizeof(dis));
	cnt=0;
	for(auto it:v)
		add(it.first,it.second),add(it.second,it.first);
	for(int i=1;i<=n;i++)D=dis[i],dfs(i,0,0);
	if(!cr)return 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if((d[i][j]>>(k-1)&1)&&dis[i][k]!=dis[j][k])return 0;
				if(!(d[i][j]>>(k-1)&1)&&dis[i][k]==dis[j][k])return 0;
			}
		}
	}
	return 1;
}
int vis[xx];
LL OR[xx];
LL lim=18446744073709551615ull;
LL now;
int ppct(LL A){return __builtin_popcountll(A>>64)+__builtin_popcountll(A&lim);}
int Gf(LL A){for(int i=1;i<=n;i++)if(A>>(i-1)&1)return i;assert(0);return 0;}
int Gb(LL A){for(int i=n;i>=1;i--)if(A>>(i-1)&1)return i;assert(0);return 0;}
int Fa;
bool CK(int x,int ano,LL T)
{
	if(vis[x])return 0;
	LL lin=-1;
	for(int i=1;i<=n;i++)
	{
		if(T>>(i-1)&1)
		{
			if(d[min(x,i)][max(x,i)]>>(ano-1)&1)
			{
				if(lin==-1)lin=d[min(ano,i)][max(ano,i)]&now;
				else lin&=(d[min(ano,i)][max(ano,i)]&now);
			}
			
		}
	}
	if(lin!=-1)
	{
		if(ppct(lin)==2)
		{
			int sk=Gf(lin);
			if(sk==x)Fa=Gb(lin);
			else Fa=sk;
			return 1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(T>>(i-1)&1)
			if(OR[i]>>(x-1)&1)return 0;
	Fa=Gf(T);
	return 1;
}
int TT[xx];
#define GET(l,r) (uniform_int_distribution<int>(l,r)(G))
#define mod _MOD
#define base _BASE
int I_S(int n){for(int i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}
int mod,base;
int imod(int l,int r){random_device R;mt19937 G(R());while(1){int x=GET(l,r);if(I_S(x))return mod=x;}}
int ibas(int l,int r){random_device R;mt19937 G(R());while(1){int x=GET(l,r);if(I_S(x))return base=x;}}
struct KEY
{
	LL a;
	int Hs()const{return a%mod;}
	bool operator==(const KEY&w)const{return a==w.a;}
};
#undef mod 
#undef base
#undef GET
struct VAL{int x,y;};
struct hash
{
	struct nod
	{
		KEY key;
		VAL val;
		int next;
	}e[(int)2e5+5];
	int h[(int)2e6+5],cnt;
	vector<int>Cl;
	void cls(){for(auto it:Cl)h[it]=0;Cl.clear();cnt=0;}
	int find(const KEY&w)
	{
		int C=w.Hs();
		for(int i=h[C];i;i=e[i].next)
			if(e[i].key==w)return i;
		return 0;
	}
	int nw(const KEY&w)
	{
		int C=w.Hs();
		++cnt,e[cnt]={w,0,h[C]},h[C]=cnt,Cl.push_back(C);
		return cnt;
	}
	VAL&operator[](const KEY&w)
	{
		int A=find(w);
		if(A)return e[A].val;
		A=nw(w);return e[A].val;
	}
}H;
void HS_init(){imod(1.5e6,2e6),ibas(200,400);}
void get(vector<int>&al,vector<int>&lf)
{
	lf.clear();
	now=0;
	for(auto it:al)now+=pw[it-1];
	H.cls();
	int tt=0;
	for(int i=1;i<=n;i++)OR[i]=0;
	for(int i=1;i<=n;i++)TT[i]=0;
	for(auto it:al)TT[it]=1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(!TT[i]||!TT[j])continue;
			if(d[i][j]&now)
			{
				if(!H.find({d[i][j]&now}))
				{
					auto&id=H[{d[i][j]&now}];
					id.x=i,id.y=j;
				}
				else 
				{
					auto&id=H[{d[i][j]&now}];
					id.x=0,id.y=0;
				}
			}
			OR[i]|=(d[i][j]&now),OR[j]|=(d[i][j]&now);
		}
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=H.cnt;i++)
	{
		auto&id=H.e[i].val;
		if(!id.x||!id.y)continue;
		int A=id.x,B=id.y;
		LL C=H.e[i].key.a;
		if(CK(A,B,C))vis[A]=1,lf.push_back(A),v.push_back(make_pair(A,Fa));
		else vis[A]=-1;
		if(CK(B,A,C))vis[B]=1,lf.push_back(B),v.push_back(make_pair(B,Fa));
		else vis[B]=-1;
	}
}
void qc(vector<int>&al,int x)
{
	for(auto it=al.begin();it!=al.end();it++)
		if(*it==x)return al.erase(it),void();
}
int nw(vector<int>&A,vector<int>&B)
{
	int tans=0;
	for(int i=1;i<=n;i++)TT[i]=0;
	for(auto it:A)TT[it]++;
	for(auto it:B)TT[it]--;
	for(int i=1;i<=n;i++)if(TT[i]==1)return i;
	return 0;
}
void zk(vector<int>&al)
{
	if(al.size()<2)return;
	if(al.size()==2)
	{
		v.push_back(make_pair(*al.begin(),*++al.begin()));
		return;
	}
	vector<int>lf;
	get(al,lf);
	for(auto it:lf)qc(al,it);
	if(!lf.size())return;
	zk(al);
}
int main(){
	HS_init();
//	freopen("a.in","r",stdin);
//	freopen("a.in","r",stdin);
	pw[0]=1;
	for(int i=1;i<=103;i++)pw[i]=pw[i-1]*2;
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<n;i++)
			for(int j=1;j<=n-i;j++)
				in(d[i][i+j]);
		v.clear(),cr=1;
		if(n==2)
			v.push_back(make_pair(1,2));
		else 
		{
			vector<int>al;
			for(int i=1;i<=n;i++)al.push_back(i);
			zk(al);
		}
		if(!cr||!check())
		{
			puts("No");
			continue;
		}
		puts("Yes");
		for(auto it:v)cout<<it.first<<" "<<it.second<<"\n";
		puts("");
	}
	pc('1',1);
	return 0;
}
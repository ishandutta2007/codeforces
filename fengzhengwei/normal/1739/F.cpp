#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
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
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}



}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
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
struct pr{int x,y;};
int n,m,k,q,a[xx],b[xx];
char s[xx];
// 
int to[12][12];
vector<int>ge[12];
string lin;
void dfs(int x,int y)
{
	lin+=char('a'+x);
	for(auto it:ge[x])if(it!=y)dfs(it,x);
}
string get()
{
	vector<int>d(12);
	memset(to,0,sizeof(to));
	int len=strlen(s+1);
	for(int i=0;i<12;i++)ge[i].clear();
	for(int i=1;i<len;i++)
	{
		int L=s[i]-'a',R=s[i+1]-'a';
		if(to[L][R])continue;
		ge[L].push_back(R);
		ge[R].push_back(L);
		to[L][R]=to[R][L]=1,d[L]++,d[R]++;
	}
	for(int i=0;i<12;i++)
		if(d[i]>2)return "*";
	lin="";
//	for(int i=0;i<12;i++)cerr<<d[i]<<"$\n";
	for(int i=0;i<12;i++)if(d[i]==1)
	{
//		cerr<<ge[i].size()<<"$\n";
		dfs(i,-1);
		return lin;
	}
	return "*";
	return lin;
}
string Z[4005],F[4005];
int p[xx];
char ST;
int f[4097][2002][12],tt;
struct tp
{
	short A;
	char B,C;
}pr[4097][2002][12];
pair<int,int> zy[2002][12][12];
int zval[2002][12][12];
bool check(const string &A,const string &B,int len)
{
	if(A.size()<len||B.size()<len)return 0;
	for(int i=0;i<len;i++)if(A[i]!=B[i])return 0;
	return 1;
}

bool check_(const string &A,const string &B,int len)
{
	if(A.size()<len||B.size()<len)return 0;
	for(int i=0;i<len;i++)if(A[A.size()-len+i]!=B[i])return 0;
	return 1;
}
char ED;
int main(){
//	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
	n=read();
//	string A="156";
//	cout<<A<<"\n";
//	reverse(A.begin(),A.end());
//	cout<<A<<"\n";
	
	for(int i=1;i<=n;i++)
	{
		a[i]=read(),scanf("%s",s+1);
		lin=get();
		Z[i]=lin;
		reverse(lin.begin(),lin.end());
		F[i]=lin;
		if(Z[i]=="*")
		{
			--i,--n;
			continue;
		}
	}
//	cerr<<n<<" "<<Z[1]<<"$\n";
	for(int i=1;i<=n;i++)a[i+n]=a[i],Z[i+n]=F[i];
	if(n==0)
	{
		cout<<"abcdefghijkl\n";
		exit(0);
	}
	// 
	n+=n;
//	for(int i=1;i<=n;i++)cout<<Z[i]<<"\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<Z[i].size();j++)
		{
			string nw=Z[i].substr(0,j);
			for(int ty=0;ty<12;ty++)
			{
				if(nw.find(char('a'+ty))!=-1ull)continue;
				string nt=nw+char('a'+ty);
				for(int to=1;to<=n;to++)
					if(check_(nt,Z[to],Z[to].size()))
					{
//						cerr<<Z[to]<<"#\n";
						zval[i][j][ty]+=a[to];
						
					}
//				if(zval[i][j][ty])
//				cerr<<i<<" "<<j<<" "<<ty<<" "<<zval[i][j][ty]<<" "<<nt<<"$\n";
				for(int tlen=min(12,(int)nt.size());tlen>=0;tlen--)
				{
					int id=-1;
					for(int to=1;to<=n;to++)
					{
						if(Z[to].size()<=tlen)continue;// 
						if(check_(nt,Z[to],tlen))
						{
							id=to;
							break;
						}
					}
					if(id!=-1)
					{
						zy[i][j][ty]={id,tlen};
						break;
					}
				}
			}
		}
	}
	memset(f,-0x3f,sizeof(f));
	f[0][1][0]=0;
	int A,B,C,ans=-1e9;
	for(int i=0;i<(1<<12);i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<12;k++)
			{
				if(f[i][j][k]<0)continue;
				if(i==(1<<12)-1&&ans<f[i][j][k])
				{
					ans=f[i][j][k];
					A=i,B=j,C=k;
				}
				for(int ty=0;ty<12;ty++)
				{
					if(i>>ty&1)continue;
					int &To=f[i+(1<<ty)][zy[j][k][ty].first][zy[j][k][ty].second];
					if(To<f[i][j][k]+zval[j][k][ty])
					{
						To=f[i][j][k]+zval[j][k][ty];
						pr[i+(1<<ty)][zy[j][k][ty].first][zy[j][k][ty].second]={j,k,ty};
					}
				}
			}
		}
	}
//	cerr<<ans<<"$\n";
	while(A)
	{
		cout<<char('a'+pr[A][B][C].C);
		auto it=pr[A][B][C];
		A-=(1<<it.C),B=it.A,C=it.B;
	}
	puts("");
	pc('1',1);
	return 0;
}
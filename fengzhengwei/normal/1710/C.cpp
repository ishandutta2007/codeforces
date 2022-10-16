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

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


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
const int yy=2e5+5;
int f[yy][2][2][2][2][2][2];
int id[]={6,5,3};
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[1][1][1][1][0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int a=0;a<=1;a++)
		{
			for(int b=0;b<=1;b++)
			{
				for(int c=0;c<=1;c++)
				{
					for(int x=0;x<=1;x++)
					{
						for(int y=0;y<=1;y++)
						{
							for(int z=0;z<=1;z++)
							{
								if(!f[i][a][b][c][x][y][z])continue;
//					cerr<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<x<<" "<<
								int LA=1-((s[i]=='0')&&a);
								int LB=1-((s[i]=='0')&&b);
								int LC=1-((s[i]=='0')&&c);
								int V=f[i][a][b][c][x][y][z];
								for(int A=0;A<=LA;A++)
								{
									for(int B=0;B<=LB;B++)
									{
										for(int C=0;C<=LC;C++)
										{
											int to=(A^B)+(B^C)*2+(A^C)*4;
											ad(f[i+1][a&&A==LA][b&&B==LB][c&&C==LC][x|(to==id[0])][y|(to==id[1])][z|(to==id[2])],V);
										}
									}
								}
								
							}
						}
					}
				}
			}
		}
	}
	ll ans=0;
		for(int a=0;a<=1;a++)
			for(int b=0;b<=1;b++)
				for(int c=0;c<=1;c++)ans+=f[n+1][a][b][c][1][1][1];
	ans%=mod;
	cout<<ans%mod<<"\n";
	pc('1',1);
	return 0;
}
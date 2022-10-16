#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
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
namespace zhs
{
	ll jiec[xx],ni[xx];
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
	int prim[xx],vis[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!vis[i])prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				vis[i*prim[j]]=1;
				if(i%prim[j]==0)break;
			}
		}
	}
}
int n,m,k,q,x,y,a[xx];
char s[xx][5];
vector<int>v[xx];
int tt[xx];
int main(){
//	freopen("a.out","w",stdout);
	int T=read();
	while(T--)
	{
		map<string,int>mp;
		n=read();
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		int cr=0;
		for(int i=1;i<=n;i++)
			if(strlen(s[i]+1)==1)cr=1;
		if(cr)
		{
			puts("YES");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(strlen(s[i]+1)==2)
			{
				if(s[i][1]==s[i][2])
				{
					cr=1;break;
				}
				swap(s[i][1],s[i][2]);
				if(mp[(s[i]+1)])
				{
					cr=1;
					break;
				}
				swap(s[i][1],s[i][2]);
				mp[(s[i]+1)]=1;
			}
		}
		
		//2,2 
		if(cr)
		{
			puts("YES");
			continue;
		}
		
		mp.clear();
		
		//2,3
		for(int i=1;i<=n;i++)
		{
			if(strlen(s[i]+1)==2)
				mp[(s[i]+1)]=1;
			if(strlen(s[i]+1)==3)
			{
				if(s[i][1]==s[i][3])
				{
					cr=1;break;
				}
				char c[5];
				c[1]=c[2]=c[3]=c[4]=0;
				c[2]=s[i][2],c[1]=s[i][3];
				if(mp[(c+1)])
				{
					cr=1;
					break;
				}
				
				
			}
		}
		mp.clear();
		
		
		for(int i=n;i>=1;i--)
		{
			if(strlen(s[i]+1)==2)
				mp[(s[i]+1)]=1;
			if(strlen(s[i]+1)==3)
			{
				if(s[i][1]==s[i][3])
				{
					cr=1;break;
				}
				char c[5];
				c[1]=c[2]=c[3]=c[4]=0;
				
				c[2]=s[i][1],c[1]=s[i][2];
				if(mp[(c+1)])
				{
//					puts("@#%");
					cr=1;
					break;
				}
			}
		}
		mp.clear();
		
		//3,3
		for(int i=1;i<=n;i++)
		{
			if(strlen(s[i]+1)==3)
			{
				
				
				swap(s[i][1],s[i][3]);
				if(mp[(s[i]+1)])
				{
					cr=1;
					break;
				}
				swap(s[i][1],s[i][3]);
				mp[(s[i]+1)]=1;
				
			}
		}
		
		if(cr)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
	pc('1',1);
	return 0;
}
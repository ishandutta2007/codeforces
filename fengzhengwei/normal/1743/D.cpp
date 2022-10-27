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

void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
void ad(int &a,ll b){(a=(a+b)%mod);}
int red(int x){return x>=mod?x-=mod:x;}

}

int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 

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

random_device R;
mt19937 G(218);
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}

#define Pr pair<int,int>
#define fi first
#define se second
int n,m,k,q,a[xx],b[xx];
int s[xx];
int main(){
	int T=1;
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			char c;
			while((c=getchar())!='0'&&c!='1');
			s[i]=c-'0';
//			s[i]=rd(0,1);
		}
		// 
		set<int>rem;
		int len=-1;
		for(int i=1;i<=n;i++)
//		if(s[i]==1) hack 7 0001000 
		rem.insert(i);
		int nst=n+1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0)
			{
				int tlen=n-i+1,cr=0,st=min(nst,i);
				for(auto it:rem)
				{
//					if(i==5)cerr<<it<<" "<<n-it+1<<" "<<tlen<<" "<<s[it+(i-st+1)-1]<<" "<<st<<"$\n";
					if(n-it+1>=tlen&&s[it+(i-st+1)-1])
					{
						cr=1;
						break;
					}
				}
				if(cr)
				{
					len=max(len,tlen),nst=min(nst,st);
					vector<int>era;
					for(auto it:rem)if(n-it+1<len||!s[it+(i-st+1)-1])era.push_back(it);
					for(auto it:era)rem.erase(it);
				}
			}
			if(rem.size()==1)// 
			{
				break;
			}
		}
		queue<int>q;
		if(len==-1)
		{
			for(int i=1;i<=n;i++)q.push(s[i]);
		}
		else 
		{
			int id=*rem.begin();
//			cerr<<id<<"#\n";
			for(int i=1;i<=n;i++)
			{
				int nw=s[i];
				if(i>=n-len+1)nw|=s[id++];
				q.push(nw);
			}
		}
		while(q.size()&&q.front()==0)q.pop();
		if(!q.size())
		{
			cout<<0<<"\n";
			continue;
		}
		else 
		{
			while(q.size())cout<<q.front(),q.pop();
			puts("");
			continue;
		}
		
		
//		if(cr){puts("Yes");continue;}
//		else {puts("No");continue;}
		
		
//		ct  
	}
	pc('1',1);
	return 0;
}
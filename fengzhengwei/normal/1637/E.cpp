#include<bits/stdc++.h>
#define ll long long
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
int n,m,k,q,a[xx],t[xx];
char s[xx];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int lsh[xx];
vector<int>v[xx];
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt]={h[x],y};
	h[x]=cnt;
}
map<pair<int,int> ,int>mp;
multiset<int> T[505];//B 
int zz[xx],vs[xx];
//ll An[xx];
int main(){
	int TT=read();
	while(TT--)
	{
		mp.clear();
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=lsh[i]=read();
		sort(lsh+1,lsh+n+1);
		int tt=unique(lsh+1,lsh+n+1)-lsh-1;
		for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+tt+1,a[i])-lsh;
		for(int i=1;i<=n;i++)t[i]=0,v[i].clear();
		for(int i=1;i<=500;i++)T[i].clear(),v[i].clear();
		//T 
		for(int i=1;i<=n;i++)t[a[i]]++;
		memset(h,0,sizeof(h[0])*(n+1));
		lsh[tt+1]=-1;
		cnt=0;
		while(m--)
		{
			int a=read(),b=read();
			int id=lower_bound(lsh+1,lsh+tt+1,a)-lsh;
			if(lsh[id]!=a)continue;
			a=id;
			id=lower_bound(lsh+1,lsh+tt+1,b)-lsh;
			if(lsh[id]!=b)continue;
			b=id;
			if(mp.find(make_pair(a,b))!=mp.end())continue;
			// 
			add(a,b),add(b,a);
			mp[make_pair(a,b)]=mp[make_pair(b,a)]=1;
		}
		
		int B=250;
		vector<int>M;
		for(int i=1;i<=n;i++)
		{
			if(t[a[i]]==0)continue;
			if(t[a[i]]>B)
			{
				t[a[i]]=0;
				M.push_back(a[i]);// 
			}
			else 
			{
				T[t[a[i]]].insert(a[i]);
//				T[t[a[i]]]++;
				//+ 1
				v[t[a[i]]].push_back(a[i]);
				t[a[i]]=0;
			}
		}
		
//		for(int i=1;i<=n;i++)cout<<i<<" "<<t[i]<<"!!\n";
		for(int i=1;i<=n;i++)t[a[i]]++;// 
		
		
		ll ans=0;
		for(auto it1:M)
		{
			for(auto it2:M)
			{
				if(it1==it2)continue;
				if(mp.find(make_pair(it1,it2))!=mp.end())continue;
				ans=max(ans,1ll*(t[it1]+t[it2])*(lsh[it1]+lsh[it2]));
			}
		}
		// 
		for(auto x:M)
		{
			for(int i=h[x];i;i=e[i].next)
			{
				if(t[e[i].to]<=B)
					T[t[e[i].to]].erase(T[t[e[i].to]].find(e[i].to));
			}
//				T[e[i].to]--;
			for(int i=1;i<=B;i++)
			{
				if(T[i].size())
				{
					ans=max(ans,1ll*(t[x]+i)*(lsh[x]+lsh[*--T[i].end()]));
				}
			}
			for(int i=h[x];i;i=e[i].next)
				if(t[e[i].to]<=B)
				T[t[e[i].to]].insert(e[i].to);
		}
		
		// 
		
		for(int i=1;i<=B;i++)sort(v[i].begin(),v[i].end());
		
		
		
		for(int i=1;i<=B;i++)
		{
			for(int j=1;j<=B;j++)zz[j]=v[j].size();
			for(auto x:v[i])
			{
				for(int k=h[x];k;k=e[k].next)
				{
					vs[e[k].to]=1;
					while(zz[t[e[k].to]]!=0&&vs[v[t[e[k].to]][zz[t[e[k].to]]-1]])
						zz[t[e[k].to]]--;
				}
				for(int j=1;j<=B;j++)
				{
					if(zz[j]!=0)
					{
						if(v[j][zz[j]-1]==x)
						{
							zz[j]--;
							while(zz[j]!=0&&vs[v[j][zz[j]-1]])zz[j]--;
							if(zz[j])
								ans=max(ans,1ll*(i+j)*(lsh[x]+lsh[v[j][zz[j]-1]]));
							zz[j]++;
						}
						else 
							ans=max(ans,1ll*(i+j)*(lsh[x]+lsh[v[j][zz[j]-1]]));
					}
					zz[j]=v[j].size();
				}
				for(int k=h[x];k;k=e[k].next)vs[e[k].to]=0;
			}
			
			
		}
//		{
//			// 
//			// 
//			multiset<int>s;
//			for(int j=1;j<=B;j++)
//			{
//				zz[j]=v[j].size();
//				if(v[j].size())s.insert((i+j)*(*--v[j].end()));
//				
//			}
//			for(auto x:v[i])
//			{
//				for(int k=h[x];k;k=e[k].next)
//				{
//					vs[e[k].to]=1;
//					while(zz[t[e[k].to]]!=0&&vs[v[t[e[k].to]][zz[t[e[k].to]]-1]])
//					{
//						
//						zz[t[e[k].to]]--;
//					}
//				}
//				
//				for(int k=h[x];k;k=e[k].next)
//				{
//					vs[e[k].to]=0;
//					zz[t[e[k].to]]=v[t[e[k].to]].size();
//				}
//			}
//			
//			for(int j=1;j<=B;j++)
//			{
//				
//			}
//		}
		
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}
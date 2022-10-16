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
int n,m,k,q,ans,a[xx],t[xx];
char s[xx];
int vs[xx],sum[xx];
vector<int>v[xx];
int cr[xx],fr[xx];
int Cr[xx],Fr[xx],b[xx];
struct node
{
	int id,l,r;
	bool operator<(const node&w)const{return l<w.l;}
};
vector<node>V;
void clear()
{
	int mx=-1e9;
	sort(V.begin(),V.end());
	for(auto it:V)
	{
		if(it.r>mx)
		{
			mx=it.r;
			cr[it.l]=1,cr[it.r]=2;
			fr[it.r]=it.l;
			if(v[it.id].size()!=1)ans+=v[it.id].size()-2;
		}
		else ans+=v[it.id].size();
	}
}
int f[xx];
int III[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),v[a[i]].push_back(i);
	ans=0;
	// 
	for(int i=1;i<=n;i++)
	{
		if(!v[i].size())continue;
		V.push_back({i,v[i][0],v[i][v[i].size()-1]});
	}
	clear();
	int tt=0;
	for(int i=1;i<=n;i++)
	{
		if(cr[i])
		{
			b[++tt]=a[i];
			III[i]=tt;
			Cr[tt]=cr[i];
			if(cr[i]==2)Fr[tt]=III[fr[i]];
		}
	}
	multiset<int>s;
//	cout<<tt<<"\n";
//	for(int i=1;i<=tt;i++)cout<<i<<" "<<b[i]<<"!!\n";
	for(int i=1;i<=tt;i++)
	{
		
		if(s.size())f[i]=max(f[i],i+(*--s.end()));
		f[i+1]=max(f[i+1],f[i]);// 
		if(Cr[i]==2)// 
		{
			if(v[b[i]].size()==1)continue;
//			cout<<i<<" ww "<<Fr[i]<<"!!\n";
			assert(s.find(f[Fr[i]]-Fr[i]-1)!=s.end());
			s.erase(s.find(f[Fr[i]]-Fr[i]-1));
		}
		if(Cr[i]==1)s.insert(f[i]-i-1);// 
	}
	cout<<f[tt+1]+ans<<"\n";
//		if(v[i].size()>=2)
//		ans+=v[i].size()-2;
//		cr[v[0]]=1;
//		nx[v[0]]=v[i].size()-1;
//		cr[v[i].size()-1]=2;// 
//	int T=read();
//	while(T--)
//	{
//		n=read();k=read();
//		for(int i=1;i<=n;i++)t[i]=0;
//		for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;
//		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+t[i];
//		int l=1,r=n;
//		ans=0;
//		while(l<=r)
//		{
//			int mid=l+r>>1;
//			if(check(mid))ans=mid,r=mid-1;
//			else l=mid+1;
//		}
////		cout<<check(n)<<"!!\n";
////		cout<<ans<<"!!\n";
//		get(ans);
//		cout<<X<<" "<<Y<<"\n";
//		int last=1,S=0;
//		if(k==1)
//		{
//			cout<<1<<" "<<n<<"\n";
//			continue;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			if(X<=a[i]&&a[i]<=Y)
//			{
//				S++;
//				if(S==1)
//				{
//					cout<<last<<" "<<i<<"\n";
//					k--;
//					last=i+1;
//					if(k==1)break;
//					S=0;
//				}
//			}
//			else S--;
//		}
//		cout<<last<<" "<<n<<"\n";
//	}
	pc('1',1);
	return 0;
}
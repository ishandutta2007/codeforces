#include<bits/stdc++.h>
#define ll long long
//#define int long long
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
const int xx=4e6+5,yy=2e5+5,mod=998244353;
//ll ksm(ll a,ll b)
//{
//	ll ans=1;
//	while(b)
//	{
//		if(b&1)ans*=a,ans%=mod;
//		a*=a,a%=mod,b>>=1;
//	}
//	return ans;
//}
//ll jiec[xx];
//ll ni[xx];
//ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
//void pr()
//{
//	jiec[0]=1;
//	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
//	ni[xx-1]=ksm(jiec[xx-1],mod-2);
//	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
//}
int T,n,m,q,k,x,y,z;
int d[xx];
struct nod{int l,r;}e[xx];
ll cst,K[xx],B[xx];
int id[xx];
ll get(ll x,int id){return K[id]*x+B[id];}
void insert(int &k,int l,int r,int a)
{
	if(!k)k=++cst,e[k].l=e[k].r=id[k]=0;
	int mid=l+r>>1;
	if(!id[k]||get(mid,id[k])<get(mid,a))swap(id[k],a);
	if(!a||l==r)return;
	if(get(l,a)>get(l,id[k]))insert(e[k].l,l,mid,a);
	if(get(r,a)>get(r,id[k]))insert(e[k].r,mid+1,r,a);
}
void cg(int &k,int l,int r,int x,int y,int a)
{
	if(!k)k=++cst,e[k].l=e[k].r=id[k]=0;
	if(x>y)return;
	if(x<=l&&r<=y)return insert(k,l,r,a);
	int mid=l+r>>1;
	if(x<=mid)cg(e[k].l,l,mid,x,y,a);
	if(mid<y)cg(e[k].r,mid+1,r,x,y,a);
}
ll ask(int k,int l,int r,int x)
{
	if(!k)return -5e16;
	ll ans=get(x,id[k]);
	int mid=l+r>>1;
	if(x<=mid)ans=max(ans,ask(e[k].l,l,mid,x));
	else ans=max(ans,ask(e[k].r,mid+1,r,x));
	return ans;
}
int tt,root;
void cls(){cst=tt=root=0;}
vector<pair<int,ll> >v[yy];//firstsecond 
int X[yy];
struct no{int a,b,c,d;ll h;};
vector<no>g[yy];
signed main(){
	B[0]=-5e16;
	T=read();
	while(T--)
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++)X[i]=read(),v[i].clear(),g[i].clear();
		v[1].push_back(make_pair(1,0));
		for(int i=1;i<=k;i++)
		{
			int a=read(),b=read(),c=read(),d=read();
			ll h=read();
			g[a].push_back({a,b,c,d,h});
		}
		
		ll ans=0;
		
		for(int i=1;i<=n;i++)
		{
			cls();
			for(auto it:v[i])
			{
				tt++,K[tt]=X[i],B[tt]=it.second-K[tt]*it.first;
				cg(root,1,m,1,it.first,tt);
				tt++,K[tt]=-X[i],B[tt]=it.second-K[tt]*it.first;
				cg(root,1,m,it.first,m,tt);
			}
			
			for(auto it:g[i])
			{
				ll now=max((ll)-5e16,ask(root,1,m,it.b));
				v[it.c].push_back(make_pair(it.d,it.h+now));
			}
//			cout<<root<<" "<<i<<" "<<v[i].size()<<" "<<tt<<"\n";
			if(i==n)ans=ask(root,1,m,m);
		}
		if(ans<-2e16)puts("NO ESCAPE");
		else cout<<-ans<<"\n";
		
	}
	pc('1',1);
	return 0;
}
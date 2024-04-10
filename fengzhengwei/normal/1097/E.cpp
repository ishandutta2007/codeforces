#include<bits/stdc++.h>
#define ll long long
#define dd double
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
    wt(x),pc(op,0);
}
const int xx=1e5+5;
int lb(int x){return x&-x;}
int sum[xx],id[xx];
void add(int x,int y,int z){for(;x<xx;x+=lb(x))sum[x]=max(sum[x],y),(sum[x]==y?id[x]=z:0);}
int T,n,m;
int get(int n)
{
    int mx=0;
    for(int i=1;i<=n;i++)
	if(1ll*i*(i+1)/2<=n)mx=max(mx,i);
    return mx;
}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans=max(ans,sum[x]);return ans;}
int Ai(int x){int ans=0,I=0;for(;x;x-=lb(x))ans=max(ans,sum[x]),(ans==sum[x]?I=id[x]:0);return I;}
int f[xx],pr[xx],a[xx];
vector<vector<int> >ans;
int is[xx],vis[xx];
vector<int>v[xx];
void dw(int n)
{
    // cout<<n<<"$$%\n";
    //  for(int i=1;i<=n;i++)cout<<i<<" "<<a[i]<<"\n";
    //  puts("");
    int mx=0,mid=0;
    for(int i=1;i<=n;i++)is[i]=0;
    for(int i=1;i<=n;i++)
    {
	mx=max(f[i],mx);
	if(mx==f[i])mid=i;
    }
    for(int i=n;i>=1;i--)
    {
	if(i==mid)
	    is[i]=1,mid=pr[mid];
	
    }
    //  for(int i=1;i<=n;i++)cout<<i<<" "<<is[i]<<"%^%^\n";
    for(int i=1;i<=n;i++)vis[i]=0;
    
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i=n;i>=1;i--)
    {
	if(is[i])
	{
	    vector<int>res;
	    int ls=a[i];
	    vector<int>an;
	    for(int j=i;j>=1;j--)
	    {
		if(vis[j])continue;
		if(a[j]>=ls)ls=a[j],vis[j]=1,res.push_back(a[j]);
	    }
	    reverse(res.begin(),res.end());
	    for(auto it:res)v[i].push_back(it);
	    
	}
    }
    for(int i=1;i<=n;i++)
    {
	if(is[i])
	{
	    int ls=a[i];
	    for(int j=i+1;j<=n;j++)
	    {
		if(vis[j])continue;
		if(a[j]<=ls)vis[j]=1,ls=a[j],v[i].push_back(a[j]);
	    }
	    ans.push_back(v[i]);
	}
    }
    for(int i=1;i<=n;i++)assert(vis[i]);
}
int N;
void G(int n,int m)
{
    if(!n)return;
    assert(m>=0);
    //  cout<<n<<" "<<m<<"\n";
    //  for(int i=1;i<=n;i++)cout<<i<<" "<<a[i]<<"%^%^%^\n";
    for(int i=1;i<=N;i++)sum[i]=id[i]=0;//N
    
    for(int i=1;i<=n;i++)
    {
	f[i]=ask(a[i])+1;
	pr[i]=Ai(a[i]);
	add(a[i],f[i],i);
    }
    int mx=0,mid=0;
    for(int i=1;i<=n;i++)mx=max(mx,f[i]);
    if(mx<=m)return dw(n);
    
    for(int i=1;i<=n;i++)
    {
	mx=max(f[i],mx);
	if(mx==f[i])mid=i;
    }
    for(int i=1;i<=n;i++)is[i]=0;
    for(int i=n;i>=1;i--)
    {
	if(i==mid)
	    is[i]=1,mid=pr[mid];
	
    }
    //  cout<<mx<<" "<<mid<<"*********\n";
    for(int i=1;i<=n;i++)vis[i]=0;
    vector<int>res;
    for(int i=1;i<=n;i++)if(is[i])res.push_back(a[i]);
    ans.push_back(res);
    int tt=0;
    for(int i=1;i<=n;i++)
    {
	if(!is[i])a[++tt]=a[i];
    }
    return G(tt,m-1);
}
int main(){
    cerr<<get(1e5)<<"#$#$\n";
    T=read();
    while(T--)
    {
	n=N=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=get(n);
	ans.clear();
	G(n,m);
//	puts("@#@$");
	cout<<ans.size()<<" ";
	puts("");
	for(auto v:ans)
	{
	    cout<<v.size()<<" ";
	    for(auto it:v)cout<<it<<" ";
	    puts("");
	}
//	puts("swswsw");
	
    }
    return 0;
}
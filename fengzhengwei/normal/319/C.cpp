#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int n,id[xx],cst,tot,root;
struct node{int l,r;}e[xx];
ll a[xx],b[xx],k[xx],B[xx],f[xx];
ll get(int x,ll y){return k[x]*y+B[x];}
void insert(int &k,int l,int r,int a)
{
	if(!k)k=++cst;
	int mid=l+r>>1;
	if(!id[k]||get(id[k],mid)>=get(a,mid))swap(id[k],a);
	if(!a||l==r)return;
	if(get(a,l)<get(id[k],l))insert(e[k].l,l,mid,a);
	if(get(a,r)<get(id[k],r))insert(e[k].r,mid+1,r,a);
}
ll ask(int k,int l,int r,int a)
{
	if(!k)return 1e18;
	int mid=l+r>>1;ll ans=0;
	if(a<=mid)ans=ask(e[k].l,l,mid,a);
	else ans=ask(e[k].r,mid+1,r,a);
	ans=min(ans,get(id[k],a));
	return ans;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	f[1]=0;k[++tot]=b[1],B[tot]=0;insert(root,0,1e9,tot);
	for(int i=2;i<n;i++)
	{
		f[i]=ask(root,0,1e9,a[i]);
		k[++tot]=b[i],B[tot]=f[i];insert(root,0,1e9,tot);
	}
	ll ans=1e18;
	for(int i=1;i<n;i++)ans=min(ans,f[i]+b[i]*a[n]);
	cout<<ans<<'\n';
	return 0;
}
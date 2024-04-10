#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=8e5+5;
int n,m,lsh[xx],uu[xx],vv[xx];
int mx[xx<<2],mn[xx<<2],add[xx<<2];
void clear()
{
	memset(mx,0,sizeof(mx));
	memset(mn,0,sizeof(mn));
	memset(add,0,sizeof(add));
}
void ad(int x,int y){mx[x]+=y;mn[x]+=y;add[x]+=y;}
void update(int x){mx[x]=max(mx[x<<1],mx[x<<1|1]);mn[x]=min(mn[x<<1],mn[x<<1|1]);}
void pd(int x){if(add[x]){ad(x<<1,add[x]),ad(x<<1|1,add[x]),add[x]=0;}}
void change(int k,int l,int r,int x,int y,int z)
{
	if(x>y)return ;
	if(x<=l&&r<=y)return ad(k,z);
	pd(k);int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y,z);
	if(mid<y)change(k<<1|1,mid+1,r,x,y,z);
	update(k);
}
int erfx(int k,int l,int r,int z)
{
	if(mx[k]<=z)return r;
	if(mn[k]>z)return l-1;
	if(l==r)return l;
	pd(k);int mid=l+r>>1;
	int s=erfx(k<<1,l,mid,z);
	if(s==mid)return erfx(k<<1|1,mid+1,r,z);
	return s;
}
int erfn(int k,int l,int r,int z)
{
	if(mx[k]<=z)return l;
	if(mn[k]>z)return r+1;
	if(l==r)return l;
	pd(k);int mid=l+r>>1;
	int s=erfn(k<<1|1,mid+1,r,z);
	if(s==mid+1)return erfn(k<<1,l,mid,z);
	return s;
}
int askx(int k,int l,int r,int x)
{
	if(x<l||x>r)return 0;
	if(l==r)return mx[k];
	pd(k);int mid=l+r>>1;
	if(x<=mid)return askx(k<<1,l,mid,x);
	return askx(k<<1|1,mid+1,r,x);
}
int askx(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return mx[k];
	pd(k);int mid=l+r>>1,ans=0;
	if(x<=mid)ans=max(ans,askx(k<<1,l,mid,x,y));
	if(mid<y)ans=max(ans,askx(k<<1|1,mid+1,r,x,y));
	return ans;
}
int ans[xx],res[xx];
vector<pair<int,int> >v[xx];
int Lp[xx],Rp[xx],Ls[xx],Rs[xx],a[xx];
signed main(){
	n=read(),m=read();
	int tt=0;
	for(int i=1;i<=n;i++)a[i]=lsh[++tt]=read();
	for(int i=1;i<=m;i++)uu[i]=read(),vv[i]=lsh[++tt]=read();
	sort(lsh+1,lsh+tt+1);
	tt=unique(lsh+1,lsh+tt+1)-lsh-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+tt+1,a[i])-lsh;
	for(int i=1;i<=m;i++)vv[i]=lower_bound(lsh+1,lsh+tt+1,vv[i])-lsh,v[uu[i]].push_back(make_pair(vv[i],i)),ans[i]++;
	tt++;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)ans[v[i][j].second]+=askx(1,1,tt,v[i][j].first-1);
		Lp[i]=a[i],Rp[i]=erfx(1,1,tt,askx(1,1,tt,a[i]-1));
		change(1,1,tt,Lp[i],Rp[i],1);
	}
	clear();
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<v[i].size();j++)ans[v[i][j].second]+=askx(1,1,tt,v[i][j].first+1);
		Ls[i]=erfn(1,1,tt,askx(1,1,tt,a[i]+1)),Rs[i]=a[i];
		change(1,1,tt,Ls[i],Rs[i],1);
	}
	for(int i=1;i<=n;i++)
	{
		change(1,1,tt,Ls[i],Rs[i],-1);
		int mx=askx(1,1,tt,1,tt);
		for(int j=0;j<v[i].size();j++)ans[v[i][j].second]=max(ans[v[i][j].second],mx);
		change(1,1,tt,Lp[i]+1,Rp[i]+1,1);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}
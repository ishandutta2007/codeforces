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
const int xx=3e5+5;
struct nod
{
	int id,x,y,z;
	bool operator<(const nod&w)const{return z==w.z?id<w.id:z<w.z;}
}a[xx],b[xx];//ab 
int n,m;
int fa[xx];
int size[xx];
int find(int x){return fa[x]==x?x:find(fa[x]);}// 
stack<pair<int,int> >stk;
int tot;
void merge(int x,int y)
{
	x=find(x);y=find(y);
	if(x==y)return;
	if(size[x]<size[y])swap(x,y);
	tot-=(size[x]&1);
	tot-=(size[y]&1);
	size[x]+=size[y];
	tot+=(size[x]&1);
	fa[y]=x;
	stk.push(make_pair(x,y));
}
int to[xx];
int ans[xx];
void pop(int x)
{
	while(stk.size()!=x)
	{
		int a=stk.top().first;
		int b=stk.top().second;
		stk.pop();
		tot-=(size[a]&1);
		size[a]-=size[b];
		tot+=(size[a]&1);
		tot+=(size[b]&1);
		fa[b]=b;
	}
}
void erf(int L,int R,int l,int r)//lL 
{
	if(l>r)return;
//	if(L==R)
//	{
//		for(int i=l;i<=r;i++)ans[i]=b[L].z;
//		return;
//	}
	int mid=l+r>>1;//
	
//	cout<<L<<" "<<R<<" "<<l<<" "<<r<<" "<<mid<<" "<<ans[mid]<<" "<<tot<<"\n";
	int ns1=stk.size();
	for(int i=l;i<=mid;i++)if(to[a[i].id]<L)merge(a[i].x,a[i].y);
	int ns2=stk.size();
	int s=R;
	for(int i=L;i<=R;i++)
	{
		if(!tot){s=i;ans[mid]=b[i].z;break;}
		if(b[i].id<=mid)merge(b[i].x,b[i].y);
		if(!tot){s=i;ans[mid]=b[i].z;break;}
	}
	if(tot)for(int i=l;i<=mid;i++)ans[i]=-1;
//	cout<<ns2<<" "<<ns1<<"\n";
//	cout<<mid<<" "<<ans[mid]<<" "<<stk.size()<<" "<<L<<" "<<R<<" "<<l<<" "<<r<<" "<<ns1<<" "<<ns2<<"\n";
	pop(ns2);
	erf(L,s,mid+1,r);
	pop(ns1);
//	cout<<mid<<" "<<ans[mid]<<"\n";
	if(ans[mid]==-1)return;
	for(int i=L;i<=s;i++)if(b[i].id<=l)merge(b[i].x,b[i].y);
	erf(s,R,l,mid-1);
}
signed main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)fa[i]=i,size[i]=1,tot=n;
	for(int i=1;i<=m;i++)
	{
		a[i].id=i;
		a[i].x=read();
		a[i].y=read();
		a[i].z=read();
		b[i]=a[i];
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)to[b[i].id]=i;
	erf(1,m,1,m);
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}
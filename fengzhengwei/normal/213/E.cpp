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
const int base=111,mod=998244353,xx=2e5+5;
ll pw[xx];
int size[xx],rd[xx],ps[xx],c[xx][2],id[xx],a[xx],b[xx],cst,n,m;
ll sum[xx];
int nd(int Id)
{
	cst++;
	rd[cst]=rand();
	id[cst]=Id;
	sum[cst]=b[Id];
	size[cst]=1;
	return cst;
}
void upd(int x)
{
	size[x]=size[c[x][0]]+size[c[x][1]]+1;
	sum[x]=(sum[c[x][0]]*pw[size[c[x][1]]+1]%mod+b[id[x]]*pw[size[c[x][1]]]+sum[c[x][1]])%mod;
}
void split(int k,int a,int &x,int &y)
{
	if(!k)return x=y=0,void();
	if(id[k]<=a)x=k,split(c[k][1],a,c[k][1],y);
	else y=k,split(c[k][0],a,x,c[k][0]);
	upd(k);
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(rd[x]<rd[y])return c[x][1]=merge(c[x][1],y),upd(x),x;
	return c[y][0]=merge(x,c[y][0]),upd(y),y;
}
int root;
void erase(int a)
{
	int x,y,z;
	split(root,a,x,y);
	split(x,a-1,x,z);
	root=merge(x,y);
}
void insert(int id)
{
	int x,y;
	split(root,id,x,y);
	root=merge(x,merge(nd(id),y));
}
signed main(){
	srand(514);
	pw[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i-1]*base%mod;
	n=read(),m=read();
	if(n==1)
	{
		cout<<m<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=m;i++)ps[b[i]]=i;// 
	ll sm=0,dlt=0;
	for(int i=1;i<=n;i++)sm*=base,sm+=a[i],sm%=mod,dlt*=base,dlt+=1,dlt%=mod;
	int ans=0;
	for(int i=1;i<=n;i++)insert(ps[i]);
//	cout<<sum[root]<<" "<<sm<<" "<<size[c[root][0]]<<" "<<sum[c[root][1]]<<"\n";
	if(sum[root]==sm)ans++;
	for(int i=n+1;i<=m;i++)
	{
		erase(ps[i-n]);
		insert(ps[i]);
		sm+=dlt;
		sm%=mod;
		if(sum[root]==sm)ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
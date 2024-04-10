#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 600001
int N,M,a[MAXN],tot,rt1,rt2,ls[MAXN],rs[MAXN],val[MAXN],dat[MAXN],siz[MAXN];
int New(int v){val[++tot]=v;dat[tot]=rand();siz[tot]=1;return tot;}
void upd(int u){siz[u]=siz[ls[u]]+siz[rs[u]]+1;}
void spl(int u,int v,int &x,int &y){if(!u){x=y=0;return;}val[u]<=v?x=u,spl(rs[u],v,rs[x],y):(y=u,spl(ls[u],v,x,ls[y]));upd(u);}
int mrg(int x,int y){if(!x||!y)return x+y;return dat[x]<dat[y]?rs[x]=mrg(rs[x],y),upd(x),x:(ls[y]=mrg(x,ls[y]),upd(y),y);}
void ins(int &rt,int v){int x,y;spl(rt,v,x,y);rt=mrg(mrg(x,New(v)),y);}
void del(int &rt,int v){int x,y,z;spl(rt,v-1,x,y);spl(y,v,y,z);y=mrg(ls[y],rs[y]);rt=mrg(mrg(x,y),z);}
int getv(int u,int r){if(!u)return 0;if(siz[ls[u]]>=r)return getv(ls[u],r);if(siz[ls[u]]+1==r)return val[u];return getv(rs[u],r-siz[ls[u]]-1);}
int getp(int &rt,int v){int x,y;spl(rt,v-1,x,y);int ans=getv(x,siz[x]);rt=mrg(x,y);return ans;}
int getn(int &rt,int v){int x,y;spl(rt,v,x,y);int ans=getv(y,1);rt=mrg(x,y);return ans;}
int main()
{
	srand(time(0));cin>>N>>M;For(i,1,N)cin>>a[i],ins(rt1,a[i]);sort(a+1,a+N+1);For(i,2,N)ins(rt2,a[i]-a[i-1]);cout<<a[N]-a[1]-getv(rt2,siz[rt2])<<endl;
	For(i,1,M)
	{
		int opt,x;cin>>opt>>x;if(opt){int a=getp(rt1,x),b=getn(rt1,x);if(a&&b)del(rt2,b-a);if(a)ins(rt2,x-a);if(b)ins(rt2,b-x);ins(rt1,x);}
		else{int a=getp(rt1,x),b=getn(rt1,x);if(a)del(rt2,x-a);if(b)del(rt2,b-x);if(a&&b)ins(rt2,b-a);del(rt1,x);}cout<<getv(rt1,siz[rt1])-getv(rt1,1)-getv(rt2,siz[rt2])<<endl;
	}
	return 0;
}
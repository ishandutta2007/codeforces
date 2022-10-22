#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,tot,rt,ls[MAXN],rs[MAXN],val[MAXN],dat[MAXN],siz[MAXN];struct S{int l,r;bool operator<(S a)const{return l<a.l;};}a[MAXN];
int New(int v){val[++tot]=v;dat[tot]=rand();siz[tot]=1;return tot;}
void upd(int u){siz[u]=siz[ls[u]]+siz[rs[u]]+1;}
void spl(int u,int v,int &x,int &y){if(!u){x=y=0;return;}val[u]<=v?x=u,spl(rs[u],v,rs[x],y):(y=u,spl(ls[u],v,x,ls[y]));upd(u);}
int mrg(int x,int y){if(!x||!y)return x+y;return dat[x]<dat[y]?rs[x]=mrg(rs[x],y),upd(x),x:(ls[y]=mrg(x,ls[y]),upd(y),y);}
void ins(int v){int x,y;spl(rt,v,x,y);rt=mrg(mrg(x,New(v)),y);}
int getr(int v){int x,y;spl(rt,v-1,x,y);int ans=siz[x];rt=mrg(x,y);return ans;}
int main()
{
	cin>>T;
	while(T--)
	{
		For(i,1,tot)ls[i]=rs[i]=val[i]=dat[i]=siz[i]=0;tot=rt=0;cin>>N;For(i,1,N)cin>>a[i].l>>a[i].r;sort(a+1,a+N+1);int res=0;
		For(i,1,N){int l=i+1,r=N,pos=i;while(l<=r){int mid=l+r>>1;if(a[mid].l<=a[i].r)pos=mid,l=mid+1;else r=mid-1;}res=max(res,pos-getr(a[i].l));ins(a[i].r);}
		cout<<N-res<<endl;
	}
	return 0;
}
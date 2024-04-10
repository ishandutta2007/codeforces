#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef double db;
int n,q;
#define Maxn 5010
int a[Maxn*20];
int maxv[Maxn*80];
void Build(int k,int l,int r){
	if(l==r){
		maxv[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	Build(k<<1,l,mid);
	Build(k<<1|1,mid+1,r);
	maxv[k]=max(maxv[k<<1],maxv[k<<1|1]);
}
int query(int k,int l,int r,int L,int R){
	if(l==L&&r==R)return maxv[k];
	int mid=(l+r)>>1;
	if(R<=mid)return query(k<<1,l,mid,L,R);
	else if(mid<L)return query(k<<1|1,mid+1,r,L,R);
	else return max(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
}
struct Seg{
	int l,r;
	db p;
	int mx;
	bool operator <(const Seg &z)const{return l==z.l?r>z.r:l<z.l;}
}seg[Maxn];
db f[Maxn][Maxn];
int head[Maxn],v[Maxn],nxt[Maxn],tot=0;
void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}
void solve(int u){
	bool flag=true;
	for(int i=head[u];i;i=nxt[i]){
		solve(v[i]);
		flag=false;
	}
	if(flag){
		f[u][0]=1-seg[u].p;
		for(int i=1;i<=q;++i)f[u][i]=1;
	}else{
		for(int i=0;i<=q;++i){
			db s=1.0;
		    for(int j=head[u];j;j=nxt[j])s*=f[v[j]][min(q,seg[u].mx+i-seg[v[j]].mx)];
		    f[u][i]+=s*(1-seg[u].p);
		    f[u][i+1]+=s*seg[u].p;
	    }	
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	Build(1,1,n);
	for(int i=1;i<=q;++i){
		scanf("%d%d%lf",&seg[i].l,&seg[i].r,&seg[i].p);
		seg[i].mx=query(1,1,n,seg[i].l,seg[i].r);
	}
	seg[++q]=(Seg){1,n,0,query(1,1,n,1,n)};
	sort(seg+1,seg+q+1);
	for(int i=1;i<=q;++i)
	for(int j=i-1;j;j--)
	if(seg[j].r>=seg[i].r){add_edge(j,i);break;}
	solve(1);
	db ans=f[1][0]*seg[1].mx;
	for(int i=1;i<=q;++i)ans=ans+(f[1][i]-f[1][i-1])*(seg[1].mx+i);
	printf("%.9lf\n",ans);
	return 0;
}
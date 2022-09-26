#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300030
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,Q,a[N];
struct Matrix{
	ll g[3][3];
	Matrix(){memset(g,~0x3f,sizeof(g));}
	Matrix operator *(const Matrix a)const{
		Matrix b;
		for(int i=1;i<=2;++i){
			for(int j=1;j<=2;++j){
				for(int k=1;k<=2;++k){
					b.g[i][j]=max(b.g[i][j],g[i][k]+a.g[k][j]);
				}
			}
		}
		return b;
	}
}pre;
struct node{
	int l,r;
	Matrix p;
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
inline void update(int i){
	tree[i].p=tree[rs].p*tree[ls].p;
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r){
		tree[i].p.g[1][1]=0,tree[i].p.g[1][2]=-a[l];
		tree[i].p.g[2][1]=a[l],tree[i].p.g[2][2]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int pos){           //
    if(tree[i].l==tree[i].r){
        tree[i].p.g[1][2]=-a[pos];
        tree[i].p.g[2][1]=a[pos];
        return;
    }
    int mid=(tree[i].l+tree[i].r)>>1;
    if(pos<=mid)Change(ls,pos);
    else Change(rs,pos);
    update(i);
}
void Solve(){
	pre.g[1][1]=pre.g[2][1]=0;
	pre.g[2][1]=pre.g[2][2]=-inf;
	build(1,1,n);
	printf("%lld\n",max((tree[1].p*pre).g[1][1],(tree[1].p*pre).g[2][1]));
	while(Q--){
		int x=read(),y=read();
		swap(a[x],a[y]);
		Change(1,x);
		Change(1,y);
		printf("%lld\n",max((tree[1].p*pre).g[1][1],(tree[1].p*pre).g[2][1]));
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),Q=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		Solve();
	} 
	return 0;
}
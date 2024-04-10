#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
#define N 500050
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,Q,a[N];
char s[N];
struct Matrix{
	int g[3][3];
	Matrix(){memset(g,0,sizeof(g));}
	inline Matrix operator *(const Matrix a){
		Matrix b;
		for(int i=1;i<=2;++i){
			for(int j=1;j<=2;++j){
				for(int k=1;k<=2;++k){
					b.g[i][j]=(b.g[i][j]+1LL*g[i][k]*a.g[k][j])%mod;
				}
			}
		}
		return b;
	}
}e,ed;
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
		tree[i].p.g[2][1]=1;
		tree[i].p.g[1][1]=a[l]+1;
		tree[i].p.g[1][2]=(a[l-1]==1)*(9-a[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(i);
}
void Change(int i,int pos){
	if(tree[i].l==tree[i].r){
		tree[i].p.g[1][1]=a[pos]+1;
		tree[i].p.g[1][2]=(a[pos-1]==1)*(9-a[pos]);
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(pos<=mid)Change(ls,pos);
	else Change(rs,pos);
	update(i);
}
int main(){
	n=read(),Q=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0';
	}
	e.g[1][1]=e.g[2][2]=1;
	ed.g[1][1]=ed.g[2][1]=1;
	build(1,1,n);
	while(Q--){
		int pos=read(),x=read();
		a[pos]=x;
		Change(1,pos);
		if(pos<n)Change(1,pos+1);
		printf("%d\n",(tree[1].p*ed).g[1][1]);
	}
	return 0;
}
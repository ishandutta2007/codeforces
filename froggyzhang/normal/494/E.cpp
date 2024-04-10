#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200010
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
int n,m,k,tot,g[N],qwq;
ll ans[40];
struct Rec{
	int X1,Y1,X2,Y2;
}a[N];
struct Border{
	int l,r,pos,type;
}b[N]; 
void Insert(int X1,int Y1,int X2,int Y2){
	if(X1>X2||Y1>Y2)return;
	g[++qwq]=X1-1,g[++qwq]=X2;
	b[++tot]={X1,X2,Y1,1};
	b[++tot]={X1,X2,Y2+1,-1};
}
bool cmp(Border a,Border b){
	return a.pos<b.pos;
}
struct node{
	int l,r,cov,sum;
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
void build(int i,int l,int r){
	tree[i].cov=tree[i].sum=0;
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
inline void update(int i){
	if(tree[i].cov>0){
		tree[i].sum=g[tree[i].r]-g[tree[i].l-1];
	}
	else{
		tree[i].sum=tree[ls].sum+tree[rs].sum;
	}
}
void Change(int i,int l,int r,int d){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].cov+=d;
		update(i);
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(l<=mid){
		Change(ls,l,r,d);
	}
	if(r>mid){
		Change(rs,l,r,d);
	}
	update(i);
}
ll Solve(int num){
	qwq=tot=0;
	ll ans=0;
	for(int i=1;i<=m;++i){
		Insert((a[i].X1-1)/num+1,(a[i].Y1-1)/num+1,a[i].X2/num,a[i].Y2/num);
	}
	if(!qwq)return 0;
	sort(g+1,g+qwq+1);
	qwq=unique(g+1,g+qwq+1)-g-1;
	for(int i=1;i<=tot;++i){
		b[i].l=lower_bound(g+1,g+qwq+1,b[i].l)-g;
		b[i].r=lower_bound(g+1,g+qwq+1,b[i].r)-g;
	}
	build(1,1,qwq);
	sort(b+1,b+tot+1,cmp);
	for(int i=1,j=1;i<=tot;i=j){
		ans+=tree[1].sum*(b[i].pos-b[i-1].pos);
		while(b[i].pos==b[j].pos&&j<=tot){
			Change(1,b[j].l,b[j].r,b[j].type);
			++j;
		}
	}
	return ans;
}
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		a[i].X1=read(),a[i].Y1=read(),a[i].X2=read(),a[i].Y2=read();
	}
	for(int i=0;i<=30;++i){
		ans[i]=Solve(1<<i);
	}
	int myh=0;
	while((1LL<<(myh+1))<=k)++myh;
	ans[myh+1]=0;
	for(int i=0;i<=myh;++i){
		if((ans[i]-ans[i+1])&1){
			printf("Hamed\n");
			return 0;
		}
	}
	printf("Malek\n");
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
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
int n,dp[N],b[N],len,lg[N];
struct PA{
	int pos,h,id;
}a[N];
bool cmp(PA a,PA b){
	return a.pos<b.pos;
}
struct node{
	int l,r,mx;
}tree[N<<2];
#define ls i<<1
#define rs i<<1|1
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
inline void update(int i){
	tree[i].mx=max(tree[ls].mx,tree[rs].mx);
}
void Insert(int i,int pos,int v){
	if(tree[i].l==tree[i].r){
		tree[i].mx=v;
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(pos<=mid){
		Insert(ls,pos,v);
	}
	else{
		Insert(rs,pos,v);
	}
	update(i);
}
int Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return tree[i].mx;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	int ans=0;
	if(l<=mid){
		ans=max(ans,Query(ls,l,r));
	}
	if(r>mid){
		ans=max(ans,Query(rs,l,r));
	}
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].pos=b[i]=read();
		a[i].h=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	build(1,1,len);
	for(int i=n;i>=1;i--){
		int r=lower_bound(b+1,b+len+1,a[i].pos+a[i].h)-b-1;
		if(r>n||r<=i){
			dp[a[i].id]=1,lg[a[i].id]=i;
		}
		else{
			lg[a[i].id]=Query(1,i+1,r);
			dp[a[i].id]=lg[a[i].id]-i+1;
		}
		Insert(1,i,lg[a[i].id]);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",dp[i]);
	}
	return 0;
}
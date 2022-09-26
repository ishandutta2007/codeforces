#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
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
int n,len,a[N],dp[N],pre[N],ans,o;
ll d,h[N],b[N];
struct node{
	int l,r,mx,pos;
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
	if(tree[ls].mx>tree[rs].mx){
		tree[i].mx=tree[ls].mx,tree[i].pos=tree[ls].pos;
	}
	else{
		tree[i].mx=tree[rs].mx,tree[i].pos=tree[rs].pos;
	}
}
void Insert(int i,int pos,int np,int v){
	if(tree[i].l==tree[i].r){
		if(v>tree[i].mx){
			tree[i].mx=v,tree[i].pos=np;
		}
		return;
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	if(pos<=mid){
		Insert(ls,pos,np,v);
	}
	else{
		Insert(rs,pos,np,v);
	}
	update(i);
}
pair<int,int> Query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r){
		return make_pair(tree[i].mx,tree[i].pos);
	}
	int mid=(tree[i].l+tree[i].r)>>1;
	pair<int,int> ans=make_pair(0,0);
	if(l<=mid){
		ans=max(ans,Query(ls,l,r));
	}
	if(r>mid){
		ans=max(ans,Query(rs,l,r));
	}
	return ans;
}
void dfs(int u){
	if(!u)return;
	dfs(pre[u]);
	printf("%d ",u);
}
int main(){
	n=read(),d=read();
	for(int i=1;i<=n;i++){
		a[i]=b[i]=h[i]=read();
	}
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+len+1,h[i])-b;
	}
	build(1,1,len);
	for(int i=1;i<=n;i++){
		int l=upper_bound(b+1,b+len+1,h[i]-d)-b-1;
		int r=lower_bound(b+1,b+len+1,h[i]+d)-b;
		pair<int,int> tmp=make_pair(0,0);
		if(l>=1){
			pair<int,int> qwq=Query(1,1,l);
			tmp=max(tmp,qwq);
		}
		if(r<=len){
			pair<int,int> qwq=Query(1,r,n);
			tmp=max(tmp,qwq);
		}
		dp[i]=tmp.first+1,pre[i]=tmp.second;
		Insert(1,a[i],i,dp[i]);
	}
	for(int i=1;i<=n;i++){
		if(dp[i]>ans){
			ans=dp[i],o=i;
		}
	}
	printf("%d\n",ans);
	dfs(o);
	return 0;
}
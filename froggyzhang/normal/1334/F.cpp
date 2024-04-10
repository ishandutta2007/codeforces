#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef long long ll;
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
int n,a[N],b[N],c[N],len,m; 
int pos[N],las[N],lastot;
ll s,dp[N],w[N];
int root[N],tot;
struct node{
	int l,r;
	ll sum,mb;
}tree[N*20+233];
inline void update(int k){
	tree[k].sum=tree[tree[k].l].sum+tree[tree[k].r].sum;
}
int build(int l,int r){
	int k=++tot;
	if(l<r){
		int mid=(l+r)>>1;
		tree[k].l=build(l,mid);
		tree[k].r=build(mid+1,r);
	}
	return k;
}
int Modify(int pre,int L,int R,int pos,int x){
	int k=0;
	if(pre<=lastot)k=++tot,tree[k]=tree[pre];
	else k=pre;
	tree[k].sum=tree[pre].sum+x;
	if(x<0)tree[k].mb=tree[pre].mb+x;
	if(L<R){
		int mid=(L+R)>>1;
		if(pos<=mid)tree[k].l=Modify(tree[pre].l,L,mid,pos,x);
		else tree[k].r=Modify(tree[pre].r,mid+1,R,pos,x);
	}
	return k;
}
ll Query(int p,int q,int L,int R,int l,int r){
	if(l>r)return 0;
	if(L>=l&&R<=r){
		return tree[q].sum-tree[p].sum;
	}
	ll ans=0;
	int mid=(L+R)>>1;
	if(l<=mid)ans+=Query(tree[p].l,tree[q].l,L,mid,l,r);
	if(r>mid)ans+=Query(tree[p].r,tree[q].r,mid+1,R,l,r);
	return ans;
}
ll Query2(int p,int q,int L,int R,int l,int r){
	if(l>r)return 0;
	if(L>=l&&R<=r){
		return tree[q].mb-tree[p].mb;
	}
	ll ans=0;
	int mid=(L+R)>>1;
	if(l<=mid)ans+=Query2(tree[p].l,tree[q].l,L,mid,l,r);
	if(r>mid)ans+=Query2(tree[p].r,tree[q].r,mid+1,R,l,r);
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		c[i]=a[i];
		las[i]=-1;
	}
	sort(c+1,c+n+1);
	len=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;++i){
		w[i]=read();
		a[i]=lower_bound(c+1,c+len+1,a[i])-c;
	}
	m=read();
	for(int i=1;i<=m;++i){
		b[i]=read();
		int myh=lower_bound(c+1,c+len+1,b[i])-c;
		if(c[myh]^b[i]){
			printf("NO\n");
			return 0;
		}
		b[i]=myh;
		las[b[i]]=b[i-1];
	}
	root[0]=build(1,len);
	for(int i=1;i<=n;++i){
		s+=w[i]; 
		root[i]=Modify(root[i-1],1,len,a[i],w[i]);
		if(las[a[i]]!=-1||las[a[i+1]]!=-1)lastot=tot;
		if(las[a[i]]==-1)continue;
		if(!las[a[i]]){
			dp[i]=s-w[i];
		}
		else if(!pos[las[a[i]]])continue;
		else{
			ll tmp=Query(root[pos[las[a[i]]]],root[i-1],1,len,las[a[i]]+1,len)+Query2(root[pos[las[a[i]]]],root[i-1],1,len,1,las[a[i]]);
			dp[i]=dp[pos[las[a[i]]]]+tmp;
		}
		if(!pos[a[i]]||dp[i]<dp[pos[a[i]]]+Query(root[pos[a[i]]],root[i],1,len,a[i]+1,len)+Query2(root[pos[a[i]]],root[i],1,len,1,a[i])){
			pos[a[i]]=i;
		}
	}
	if(!pos[b[m]]){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%lld\n",dp[pos[b[m]]]+Query(root[pos[b[m]]],root[n],1,len,b[m]+1,len)+Query2(root[pos[b[m]]],root[n],1,len,1,b[m]));
//	getchar(),getchar();
	return 0;
}
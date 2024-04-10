#include<vector> 
#include<bitset>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 10005

bitset<M> sum[M<<2];

vector<int> G[M<<2];
void Update(int L,int R,int p,int l,int r,int x) {
	if(L==l&&R==r) {
		G[p].push_back(x);
		return ;
	}
	int mid=L+R>>1;
	if(r<=mid) Update(L,mid,p<<1,l,r,x);
	else if(l>mid) Update(mid+1,R,p<<1|1,l,r,x);
	else {
		Update(L,mid,p<<1,l,mid,x);
		Update(mid+1,R,p<<1|1,mid+1,r,x);	
	}
}
void Query(int L,int R,int p) {
	if(L==R) {
		sum[p]=1;
		FOR(i,0,G[p].size()-1) sum[p]|=sum[p]<<G[p][i];
		return ;
	}
	int mid=L+R>>1;
	Query(L,mid,p<<1);
	Query(mid+1,R,p<<1|1);
	
	sum[p]=sum[p<<1]|sum[p<<1|1];
	FOR(i,0,G[p].size()-1) sum[p]|=sum[p]<<G[p][i];
}
int Ans[M];
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	FOR(i,1,q) {
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		Update(1,n,1,l,r,x);
	}
	Query(1,n,1);
	int top=0;
	FOR(i,1,n) if(sum[1][i]) Ans[++top]=i;
	printf("%d\n",top);
	FOR(i,1,top) printf("%d ",Ans[i]);
	putchar('\n');
	return 0;
}
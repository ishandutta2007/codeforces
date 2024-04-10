#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 500005

struct Ask{
	int x,id;
};
vector<Ask> G[M];
int mn[M<<2];
int pre[M];
int MIN(int x,int y) {
	return pre[x]<pre[y]?x:y;	
}
void Update(int L,int R,int p,int x) {
	if(L==R) {
		mn[p]=L;
		return ;	
	}
	int mid=L+R>>1;
	if(x<=mid) Update(L,mid,p<<1,x);
	else Update(mid+1,R,p<<1|1,x);
	mn[p]=MIN(mn[p<<1],mn[p<<1|1]);
}
int Query(int L,int R,int p,int l,int r) {
	if(L==l&&R==r) return mn[p];
	int mid=L+R>>1;
	if(r<=mid) return Query(L,mid,p<<1,l,r);
	else if(l>mid) return Query(mid+1,R,p<<1|1,l,r);
	else return MIN(Query(L,mid,p<<1,l,mid),Query(mid+1,R,p<<1|1,mid+1,r));
}
int lst[M];
int val[M];
int Ans[M];
int main() {
	int n,m;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&val[i]);
	scanf("%d",&m);
	FOR(i,1,m) {
		int l,r;
		scanf("%d%d",&l,&r);
		G[r].push_back((Ask){l,i});
	}
	FOR(i,1,n) {
		if(lst[val[i]]) {
			pre[lst[val[i]]]=n;
			Update(1,n,1,lst[val[i]]);
		}
		pre[i]=lst[val[i]];
		Update(1,n,1,i);
		lst[val[i]]=i;
		
		FOR(j,0,G[i].size()-1) {
			int tmp=Query(1,n,1,G[i][j].x,i);
			if(pre[tmp]<G[i][j].x) tmp=val[tmp];
			else tmp=0;
			Ans[G[i][j].id]=tmp;
		}
	}
	FOR(i,1,m) printf("%d\n",Ans[i]);
	return 0;
}
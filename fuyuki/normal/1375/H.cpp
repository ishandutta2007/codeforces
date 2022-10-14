#include<bits/stdc++.h>
using namespace std;
#define rz resize
#define I inline int
#define V inline void
#define VI vector<int>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1<<12,M=1<<16,B=1<<8,K=1<<22;
int n,m,tot,a[N],c[K],d[K],pos[N],ans[M];
I merge(int x,int y){
	if(!x||!y)return!x*y+!y*x;
	return c[tot]=x,d[tot]=y,++tot;
}
struct seg{
	VI val;vector<VI>id;
	V init(int x){val.rz(x),id.rz(x);FOR(i,0,x-1)id[i].rz(x-i);}
	seg(int x=-1){if(~x)init(1),val[0]=pos[x],id[0][0]=pos[x]+1;}
	I ask(int l,int r)const{
		if(r<val.front()||l>val.back())return 0;
		l=lower_bound(val.begin(),val.end(),l)-val.begin();
		r=upper_bound(val.begin(),val.end(),r)-val.begin()-1;
		return l>r?0:id[l][r-l];
	}
	seg update(const seg&x,const seg&y){
		init(x.val.size()+y.val.size());
		merge(x.val.begin(),x.val.end(),y.val.begin(),y.val.end(),val.begin());
		FOR(i,0,val.size()-1)FOR(j,i,val.size()-1)
			id[i][j-i]=merge(x.ask(val[i],val[j]),y.ask(val[i],val[j]));
		return*this;
	}
}t[N/B];
V input(){
	scanf("%d%d",&n,&m),tot=n--;
	FOR(i,0,n)scanf("%d",a+i),a[i]--;
}
seg solve(int L,int R){
	if(L==R)return(L);
	int mid=L+R>>1;seg out;
	return out.update(solve(L,mid),solve(mid+1,R));
}
V init(){
	FOR(i,0,n)pos[a[i]]=i;
	FOR(i,0,n/B)t[i]=solve(i*B,min(n,i*B+B-1));
}
V work(){
	int l,r;
	FOR(i,0,m-1){
		scanf("%d%d",&l,&r),l--,r--;
		FOR(j,0,n/B)ans[i]=merge(ans[i],t[j].ask(l,r));
	}
	cout<<tot<<'\n';
	FOR(i,n+1,tot-1)cout<<c[i]<<' '<<d[i]<<'\n';
	FOR(i,0,m-1)cout<<ans[i]<<' ';
}
int main(){
	input();
	init();
	work();
	return 0;
}
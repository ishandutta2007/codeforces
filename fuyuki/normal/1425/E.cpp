#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
const int N=1e5+2,INF=0x3f3f3f3f;
ll pre[N],nxt[N],bac[N];
int n,k,a[N],d[N],c[N];
V cmax(ll&x,ll y){if(x-y>>63)x=y;}
V input(){
	scanf("%d%d",&n,&k);
	FOR(i,1,n)scanf("%d",a+i);
	FOR(i,1,n)scanf("%d",d+i);
}
struct node{
	ll sum,val;
	node operator+(const node&u)const{
		return(node){sum+u.sum,max(u.val,val+u.sum)};
	}
}pro[N],suf[N],t[N];
V init(){
	c[0]=INF;
	FOR(i,1,n)pre[i]=pre[i-1]+a[i];
	ROF(i,n,1)nxt[i]=nxt[i+1]+a[i];
	FOR(i,1,n)c[i]=min(c[i-1],d[i]);
	FOR(i,1,n)t[i]=(node){a[i],a[i]-d[i]};
	pro[0]=(node){0,-INF};
	FOR(i,1,n)pro[i]=pro[i-1]+t[i];
	ROF(i,n,1)suf[i]=t[i]+suf[i+1];
}
ll ask0(ll out=0){
	FOR(i,1,n)cmax(out,nxt[i]-d[i]);
	return out;
}
ll ask1(ll out=0){
	FOR(i,2,n-1)cmax(out,max(0ll,pre[i]-c[i])+max(nxt[i+1]-d[i+1],0ll));
	FOR(i,2,n-1)
		cmax(out,(pro[i-1]+suf[i+1]).val+max(0,a[i]-d[i]));
	FOR(i,2,n)cmax(out,nxt[i]-d[i]);
	return out;
}
V work(){
	if(k==0)return void(cout<<ask0());
	if(k==1)return void(cout<<ask1());
	cout<<max(max(0ll,pre[n]-c[n-1]),0ll+a[n]-d[n]);
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}
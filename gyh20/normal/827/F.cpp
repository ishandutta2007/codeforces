#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=1000000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
struct node{
	int pos,dis;
	bool operator <(const node A)const{return dis>A.dis;}
}h[2000002];
struct Seg{
	int l,r,id;
	bool operator <(const Seg A)const{return l>A.l;}
};
int dis[2000002],cnt,n,m,U[2000002],V[2000002],L[2000002],R[2000002];
priority_queue<Seg>S[1000002];
priority_queue<node>Q;
vector<int>W; 
inline void upd(priority_queue<Seg>&A,re int l,re int r){
	while(!A.empty()){
		re Seg x=A.top();
		re int y=max(l+1,l+1+((x.l+1-(l+1)+1>>1)<<1));
		if(y>r+1)break;A.pop();
		if(y>x.r)continue;
		if(dis[x.id]==-1)dis[x.id]=y,Q.push((node){x.id,y});
	}
}
inline void Ins(re int x,re int y,re int l,re int r){
	U[++cnt]=x,V[cnt]=y,L[cnt]=l,R[cnt]=r;
	S[x].push((Seg){l,r,cnt});
}
int main(){
	n=read(),m=read();if(n==1)return puts("0"),0;
	for(re int i=1;i<=m+m+m+m;++i)dis[i]=-1;
	for(re int i=1;i<=m;++i){
		re int x=read(),y=read(),l=read(),r=read();
		Ins(x,y+n,l,r),Ins(x+n,y,l,r),Ins(y,x+n,l,r),Ins(y+n,x,l,r);
	}upd(S[1],0,0);
	while(!Q.empty()){
		re node x=Q.top();Q.pop();
		if(V[x.pos]%n==0)return printf("%d",x.dis),0;
		upd(S[V[x.pos]],x.dis,R[x.pos]);
	}
	puts("-1");
}
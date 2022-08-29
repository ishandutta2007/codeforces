#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	//
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
struct node{
	int x,id;
	bool operator <(const node a)const{
		return x==a.x?id>a.id:x<a.x;
	}
	bool operator ==(const node a)const{
	return x==a.x&&id==a.id;}
}p[500002];
priority_queue<node>q,d;inline node first(){	while(!d.empty()&&d.top()==q.top())d.pop(),q.pop();	return q.empty()?(node){0,0}:q.top();}
int n,m,k;
bool vis[500002];
int main(){
	m=read();k=1;
	while(m--){
		re int x=read();
		if(x==1){
			++n;
			p[n]=(node){read(),n};
			q.push(p[n]);
		}
		else if(x==2){
			while(vis[k])++k;
			vis[k]=1,d.push(p[k]);
			printf("%d ",k);
		}
		else{
			node x=first();
			d.push(x);
			vis[x.id]=1;
			printf("%d ",x.id);
		}
	}
}
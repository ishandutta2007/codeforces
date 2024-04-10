#include<bits/stdc++.h>
using namespace std;
#define re register
int n,m,a[200002],b[200002],c[200002],f[200002];
struct node {
	int t1,t2,id;
}t[200002];
map<int,int> ma;
const int Mxdt=200000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read() {
	re int t=0;
	re char v=gc();
	while(v<'0')v=gc();
	while(v>='0') {
		t=(t<<3)+(t<<1)+v-'0';
		v=gc();
	}
	return t;
}
bool cmp(const node &x,const node &y) {return x.t1>y.t1||x.t1==y.t1&&x.t2>y.t2;}
int main() {
	n=read();
	for(re int i=1;i<=n;++i)++ma[read()];
	m=read();
	for(re int i=1;i<=m;++i)t[i].t1=ma[read()],t[i].id=i;
	for(re int i=1;i<=m;++i)t[i].t2=ma[read()];
	sort(t+1,t+1+m,cmp);
	printf("%d",t[1].id);
}
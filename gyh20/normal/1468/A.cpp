#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	//
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline char pc(char ch,bool bj) {
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read() {
	re int t=0;
	re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,a[500002],t,ans,s[500005],b[500002],c1[500002],stk[500002],tp,l[500002];
vector<int>v[500002];
inline void add1(re int x,re int y){for(;x<=n;x+=x&(-x))c1[x]+=y;}
inline int ask1(re int x){
	re int sum=0;
	for(;x;x-=x&(-x))sum+=c1[x];
	return sum;
}
struct BIT {
	int c[500002];
	inline void clr() {
		for(int i=0; i<=n; i++)c[i]=0;
	}
	inline void add(re int x,re int y,re int opt=0) {
		if(!x)x=1;
		if(opt)s[y]=min(s[y],x);
		for(; x<=n; x+=x&(-x))c[x]=max(c[x],y);
	}
	inline int ask(re int x) {
		re int s=0;
		for(; x; x-=x&(-x))s=max(s,c[x]);
		return s;
	}
} C[2];
//c[0]:a[i]<a[lst] c[1]:a[i]>=a[lst]
int main() {
	t=read();
	while(t--) {
		n=read();
		C[0].clr(),C[1].clr(),ans=0;
		for(re int i=1; i<=n; ++i)s[i]=0x3f3f3f3f,v[i].clear(),a[i]=read();
		s[0]=0;a[0]=1;tp=0;
		for(re int i=n;i;--i){
			while(tp&&a[i]>=a[stk[tp]])--tp;
			l[i]=stk[tp];
			stk[++tp]=i;
			if(l[i])v[l[i]].push_back(i);
		}
		v[1].push_back(0);
		for(re int i=0; i<=n; ++i) {
			re int x=C[0].ask(a[i])+1;
			b[i]=x;
			C[0].add(a[i],x),ans=max(ans,x);
			for(auto &y:v[i])C[0].add(a[y],b[y]+1),ans=max(ans,b[y]+1);
		}
		printf("%d\n",ans-1);
	}
}
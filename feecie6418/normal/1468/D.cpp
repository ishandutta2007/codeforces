#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	//
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,t,ans,tim,a,b;
multiset<int>s;
multiset<int>::iterator it;
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),a=read(),b=read();
		if(a>b)a=n-a+1,b=n-b+1;
		s.clear(),--b;ans=0;
		for(re int i=1;i<=m;++i)s.insert(read());
		for(re int i=1;i<=m&&a!=b;++i){
			it=s.lower_bound(b);
			if(it!=s.begin())--it,++ans,s.erase(it);
			--b;
		}
		printf("%d\n",ans);
	}
}
#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B;
char s[1000002];
inline int Log(re int x){
	re int s=0;
	while(x)x/=10,++s;
	return s;
}
int main(){
	t=read();
	while(t--){
		n=read();
		priority_queue<int>QA,QB;
		for(re int i=1;i<=n;++i)QA.push(read());
		for(re int i=1;i<=n;++i)QB.push(read());
		ans=0;
		while(!QA.empty()){
			re int x=QA.top(),y=QB.top();
			QA.pop(),QB.pop();
			if(x==y)continue;
			else{
				if(x>y)x=Log(x);else y=Log(y);++ans;
				QA.push(x),QB.push(y); 
			}
		}
		printf("%d\n",ans);
	}
}
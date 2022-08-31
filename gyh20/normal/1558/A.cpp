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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,a[1000002],b[1000002],ans,t,A,B;
char s[1000002];
int main(){
	t=read();
	while(t--){
		A=read(),B=read();
		m=0;
		re int pa=(A+B+1)>>1,pb=(A+B)>>1;
		re int ans1=abs(pa-A),ans2=A+B-abs(A-pb);
		for(re int i=ans1;i<=ans2;i+=2){
			a[++m]=i;
			if((A+B)&1)a[++m]=A+B-i; 
		}
		sort(a+1,a+m+1),m=unique(a+1,a+m+1)-a-1;
		printf("%d\n",m);
		for(re int i=1;i<=m;++i)printf("%d ",a[i]);
		puts("");
		
	}
}
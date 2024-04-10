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
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,t,a[1000002],ans;
vector<int>A,B;
int main(){
	n=read(),m=read();
	while(n--)++a[read()];
	for(re int i=1;i<m;++i)
		if(a[i]%(i+1))return puts("No"),0;
		else a[i+1]+=a[i]/(i+1);
	puts("Yes");
}
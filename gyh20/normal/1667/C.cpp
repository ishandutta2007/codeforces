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
int t,n,m,a[1000002],ans;
vector<int>A,B;
char s[1000002];
int main(){
	n=read();
	re int n1=(n+2)/3,n2=n/3;
	for(re int i=1;i<=n1;++i)A.push_back(i),B.push_back(n1-i+1);
	re int pos=n;
	if(n1==n2){
	for(re int i=n;i>=n-n2+1;--i){
		A.push_back(i),B.push_back(pos);
		++pos;
		if(pos>n)pos-=n2;
	}
	}
	else{
		pos=n-n2+1;
	for(re int i=n;i>=n-n2+1;--i){
		A.push_back(i),B.push_back(pos);
		++pos;
		if(pos>n)pos-=n2;
	}
		
	}
	printf("%d\n",A.size());
	for(re int i=0;i<A.size();++i)printf("%d %d\n",A[i],B[i]);
}
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
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp;
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		vector<int>A,B;
		for(re int i=1;i<=n;++i)
			if(a[i]==0)A.push_back(read());
			else B.push_back(read());
		sort(A.begin(),A.end()),sort(B.begin(),B.end());
		reverse(A.begin(),A.end()),reverse(B.begin(),B.end());
		long long s1=0,s2=0,sum=0;
		for(auto z:A)sum+=z;for(auto z:B)sum+=z;
		for(re int i=0;i<min(A.size(),B.size());++i)s1+=A[i],s1+=B[i];
		if(A.size()==B.size()&&min(A.size(),B.size()))s1-=min(A[min(A.size(),B.size())-1],B[min(A.size(),B.size())-1]);
		printf("%lld\n",sum+s1);
	}
}
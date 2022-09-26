#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
const int mx=100000;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,d[N];
inline int C2(int x){
	return x*(x-1)/2;
}
inline int C3(int x){
	return x*(x-1)*(x-2)/6;
}
inline int Solve(int A,int B,int C){
	int g1=__gcd(A,B),g2=__gcd(A,C),g3=__gcd(B,C);
	int g0=__gcd(A,__gcd(B,C));
	int ans=d[A]*d[B]*d[C];
	ans-=C2(d[g1])*d[C]+C2(d[g2])*d[B]+C2(d[g3])*d[A];
	ans+=2*C2(d[g0])+4*C3(d[g0]);
	ans+=(d[g1]+d[g2]+d[g3]-3*d[g0])*C2(d[g0]);
	ans-=(d[g1]-d[g0])*(d[g2]-d[g0])*(d[g3]-d[g0]);
	return ans;
}
int main(){
	for(int i=1;i<=mx;++i){
		for(int j=i;j<=mx;j+=i){
			++d[j];
		}
	}
	T=read();
	while(T--){
		int A=read(),B=read(),C=read();
		printf("%d\n",Solve(A,B,C));
	}
	return 0;
}
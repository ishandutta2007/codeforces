#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
//#define myh akioi
int T,n,k;
int X;
inline int Minus(int,int);
inline int Ask(int x){
	printf("%d\n",x);
	fflush(stdout);
	#ifdef myh
	if(X^x){
		X=Minus(x,X);
		return 0;
	}
	return 1;
	#endif
	return read();
}
inline int Add(int x,int y){
	int pw=1,z=0;
	while(x||y){
		z+=pw*((x+y)%k);
		x/=k,y/=k;
		pw*=k;
	}
	return z;
}
inline int Minus(int x,int y){
	int pw=1,z=0;
	while(x||y){
		z+=pw*(((x-y)%k+k)%k);
		x/=k,y/=k;
		pw*=k;
	}
	return z;
}
void Solve(){
	n=read(),k=read();
	#ifdef myh
	X=read();
	#endif
	int now=0;
	for(int i=0;i<n;++i){
		int t;
		if(Ask(t=(i&1?Minus(now,i):Add(now,i))))break;
		now=Minus(t,now);
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}
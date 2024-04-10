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
int T,A,B;
int main(){
	T=read();
	while(T--){
		A=read(),B=read();
		if(B==1){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%lld %lld %lld\n",1LL*(B+1)*A,1LL*(B-1)*A,2LL*A*B);
	}
	return 0;
}
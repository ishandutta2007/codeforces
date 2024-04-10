#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
int T,n;
void Solve(){
	n=read();
	int x=0;
	for(int i=1;i<=n;++i){
		x=(x+read())%n;
	}
	printf("%lld\n",1LL*x*(n-x));
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}
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
int T,n,k;
int Solve(){
	if(n&1){
		return (k+k/(n/2))%n+1;	
	}
	else{
		return k%n+1;
	}
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read()-1;
		printf("%d\n",Solve());
	}
	return 0;
}
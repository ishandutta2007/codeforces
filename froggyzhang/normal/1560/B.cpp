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
int T,a,b,c;
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read();
		int n=2*(max(a,b)-min(a,b));
		if(max(max(a,b),c)>n){
			puts("-1");continue;
		}
		printf("%d\n",c>n/2?c-n/2:c+n/2);
	}
	return 0;
}
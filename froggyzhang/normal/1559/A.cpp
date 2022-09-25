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
int n;
int main(){
	int T=read();
	while(T--){
		n=read();
		int ans=(1LL<<31)-1;
		while(n--)ans&=read();
		printf("%d\n",ans);
	}
	return 0;
}
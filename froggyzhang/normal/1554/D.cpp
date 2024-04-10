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
int T;
int main(){
	T=read();
	while(T--){
		int n=read();
		if(n==1){putchar('a'),putchar('\n');continue;}
		if(n&1)putchar('z'),--n;
		for(int i=1;i<n/2;++i)putchar('a');
		putchar('b');
		for(int i=1;i<=n/2;++i)putchar('a');
		putchar('\n');	
	}
	return 0;
}
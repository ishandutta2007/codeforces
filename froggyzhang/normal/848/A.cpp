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
int k;
int main(){
	k=read();
	char c='a';
	do{
		int n=1;
		while(n*(n+1)/2<=k)++n;
		k-=n*(n-1)/2;
		for(int i=1;i<=n;++i)putchar(c);
		++c;
	}while(k);
	return 0;
}
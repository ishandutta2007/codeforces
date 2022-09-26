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
	n=read();
	for(int i=2;i<=n;++i){
		if(n%i==0){
			printf("%d%d\n",i,n/i);
			return 0;
		}
	}
	return 0;
}
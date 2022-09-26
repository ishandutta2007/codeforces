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
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		if(n&1){
			printf("%d %d %d\n",1,n>>1,n>>1);
		}
		else if(n%4==0){
			printf("%d %d %d\n",n>>2,n>>2,n>>1);
		}
		else{
			printf("%d %d %d\n",2,(n-2)>>1,(n-2)>>1);
		}
	} 
	return 0;
}
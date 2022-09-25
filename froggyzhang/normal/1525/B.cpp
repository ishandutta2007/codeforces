#include<bits/stdc++.h>
using namespace std;
#define N 55
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
int T,n,a[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();	
		}
		bool ok=true;
		for(int i=1;i<=n;++i){
			if(a[i]^i){ok=false;break;}
		}
		if(ok){
			printf("0\n");
		}
		else if(a[1]==1||a[n]==n){
			printf("1\n");	
		}
		else if(a[1]==n&&a[n]==1){
			printf("3\n");
		}
		else{
			printf("2\n");
		}
	}
	return 0;
}
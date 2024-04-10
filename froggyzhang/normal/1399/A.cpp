#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
#define N 233
inline int read(){
	int x=0,f=1;
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
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	bool ok=true;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		if(a[i]-a[i-1]>1){
			ok=false;break;
		}
	}
	printf(ok?"YES\n":"NO\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}
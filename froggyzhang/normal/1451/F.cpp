#include<bits/stdc++.h>
using namespace std;
#define N 233
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
int T,a[N],n,m;
void Solve(){
	n=read(),m=read();
	for(int i=1;i<=n+m;++i)a[i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i+j]^=read();
		}
	}
	for(int i=1;i<=n+m;++i){
		if(a[i])return (void)(printf("Ashish\n"));
	}
	printf("Jeel\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}
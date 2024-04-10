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
int T,n;
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			printf("%d ",(j-i)*2==n?0:((j-i)*2<n?1:-1));
		}
	}
	printf("\n");
}				
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}
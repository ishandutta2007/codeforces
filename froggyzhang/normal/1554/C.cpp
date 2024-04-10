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
int T,n,m,h[31];
void Solve(){
	n=read(),m=read();
	int ans=0;
	for(int i=30;i>=0;--i){
		if((ans|n|h[i])<=m)ans|=1<<i;
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	for(int i=1;i<=30;++i)h[i]=h[i-1]<<1|1;
	while(T--){
		Solve();
	}
	return 0;
}
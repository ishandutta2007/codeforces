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
int T,n,a[233];
void Solve(){
	static int vis[233];
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		a[i]=read();
		++vis[a[i]];
	}
	for(int i=0;i<=100;++i){
		if(vis[i])printf("%d ",i),--vis[i];
	}
	for(int i=0;i<=100;++i){
		while(vis[i]--)printf("%d ",i);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}
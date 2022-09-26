#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,p[N],a[N];
void Solve(){
	static int vis[N];
	n=read();
	for(int i=1;i<=n;++i)p[i]=read(),vis[i]=0;
	int now=0;
	for(int i=n,k=n;i>=1;--i){
		if(vis[i])continue;
		int t=k;
		while(p[t]^i)--t;
		for(int j=t;j<=k;++j){
			a[++now]=p[j];
			vis[p[j]]=1;
		}
		k=t-1;
	}
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
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
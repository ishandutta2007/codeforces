#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int T,m,a[2][N],suf[N],pre[N];
void Solve(){
	m=read();
	for(int i=0;i<2;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	suf[m+1]=0;
	for(int i=m;i>=1;--i){
		suf[i]=suf[i+1]+a[0][i];
	}
	for(int i=1;i<=m;++i){
		pre[i]=pre[i-1]+a[1][i];
	}
	int ans=2e9;
	for(int i=1;i<=m;++i){
		ans=min(ans,max(pre[i-1],suf[i+1]));
	}
	printf("%d\n",ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}
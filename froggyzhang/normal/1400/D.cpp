#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 3003
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
int T,n,a[N],pre[N][N],suf[N][N];
void Solve(){
	for(int i=1;i<=n;++i){
		pre[0][i]=suf[n+1][0]=0;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			pre[i][j]=pre[i-1][j];
		}
		++pre[i][a[i]];
	}
	for(int i=n;i>=1;--i){
		for(int j=1;j<=n;++j){
			suf[i][j]=suf[i+1][j];
		}
		++suf[i][a[i]];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			ans+=pre[i-1][a[j]]*suf[j+1][a[i]];
		}
	}
	printf("%I64d\n",ans);
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		Solve();
	}
	return 0;
}
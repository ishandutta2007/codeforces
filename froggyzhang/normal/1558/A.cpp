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
int T,a,b,ok[N];
void Solve(){
	a=read(),b=read();
	int n=a+b;
	for(int i=0;i<=n;++i)ok[i]=0;
	for(int h=0;h<=1;++h){
		int t=(n+h)/2;
		for(int i=0;i<=min(t,a);++i){
			int g=a-i;
			if(g>n-t)continue;
			ok[g+t-i]=1;
		}
	}
	int ans=0;
	for(int i=0;i<=n;++i)ans+=ok[i];
	printf("%d\n",ans);
	for(int i=0;i<=n;++i){
		if(ok[i])printf("%d ",i);
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
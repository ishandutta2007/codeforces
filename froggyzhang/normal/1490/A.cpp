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
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	int ans=0;
	for(int i=2;i<=n;++i){
		int x=min(a[i-1],a[i]);
		int y=max(a[i-1],a[i]);
		while((x<<1)<y)++ans,x<<=1;
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
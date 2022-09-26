#include<bits/stdc++.h>
using namespace std;
#define N 2020
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
	sort(a+1,a+n+1,[&](int i,int j){return (i&1)==(j&1)?i<j:(i&1)<(j&1);});
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			ans+=__gcd(a[i],a[j]<<1)>1;
		}
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
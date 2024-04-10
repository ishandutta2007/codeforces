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
int T;
ll a[N];
bool Solve(){
	int n=read();
	ll k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	ll s=a[2]-a[1];
	for(int i=2;i<n;++i){
		s=__gcd(s,a[i+1]-a[i]);
	}
	for(int i=1;i<=n;++i){
		if(!((a[i]-k)%s))return true;
	}
	return false;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}
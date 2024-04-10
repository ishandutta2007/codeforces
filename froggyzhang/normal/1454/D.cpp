#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
int T;
ll n;
void Solve(){
	n=read();
	ll p=1,m=n;
	int mx=0;
	for(ll i=2;i*i<=n;++i){
		if(n%i==0){
			int cnt=0;
			while(n%i==0)++cnt,n/=i;
			if(cnt>mx)mx=cnt,p=i;
		}
	}
	if(n>1&&!mx)mx=1,p=n;
	printf("%d\n",mx);
	for(int i=1;i<mx;++i){
		printf("%lld ",p),m/=p;
	}
	printf("%lld\n",m);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}
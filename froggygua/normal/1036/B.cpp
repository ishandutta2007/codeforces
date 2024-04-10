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
int Q;
int main(){
	Q=read();
	while(Q--){
		ll n=read(),m=read(),ans=0,k=read();
		if(n>m)swap(n,m);
		m-=n,k-=n,ans+=n;
		n=0;
		if(k<m){
			puts("-1");
			continue;
		}
		if(k&1&&!(m&1)){
			ans+=k-2;
		}
		else{
			ans+=k-(m&1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
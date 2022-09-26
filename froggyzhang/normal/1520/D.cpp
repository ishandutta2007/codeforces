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
int T,n;
map<int,int> mp;
ll Solve(){
	n=read();
	mp.clear();
	ll ans=0;
	for(int i=1;i<=n;++i){
		int x=read();
		ans+=mp[x-i];
		++mp[x-i];
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%lld\n",Solve());
	}
	return 0;
}
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
int T,n,a[N],m;
map<int,int> mp;
void Solve(){
	n=read();
	mp.clear();
	m=0;
	for(int i=1;i<=n;++i){
		++mp[read()];
	}
	for(auto [x,t]:mp){
		a[++m]=t;
	}
	int mx=0;
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i){
		mx=max(mx,(m-i+1)*a[i]);
	}
	printf("%d\n",n-mx);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;	
}
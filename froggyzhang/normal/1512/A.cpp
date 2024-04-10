#include<bits/stdc++.h>
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
int T,n,a[233];
int Solve(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	map<int,int> mp;
	for(int i=1;i<=n;++i){
		++mp[a[i]];
	}
	int qwq=0;
	for(auto [x,y]:mp){
		if(y==1)qwq=x;
	}
	for(int i=1;i<=n;++i){
		if(a[i]==qwq)return i;
	}
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}
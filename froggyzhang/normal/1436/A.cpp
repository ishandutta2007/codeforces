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
int T,m,n;
bool Solve(){
	int s=0;
	n=read(),m=read();
	for(int i=1;i<=n;++i)s+=read();
	return s==m;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 30030
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
int n,a[N],T;
bool Solve(){
	int mn=1e6+233;
	for(int i=n;i>=2;--i){
		mn=min(mn,a[i]);
		if(a[i]>a[i-1]){
			mn-=a[i]-a[i-1];
			if(mn<0)return false;
		}
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}
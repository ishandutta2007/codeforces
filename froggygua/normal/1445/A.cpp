#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 233
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
int a[N],b[N],x,n,T;
bool Solve(){
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,greater<int>());
	for(int i=1;i<=n;++i){
		if(a[i]+b[i]>x)return false;
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		n=read(),x=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i){
			b[i]=read();
		}
		printf(Solve()?"Yes\n":"No\n");
	}
	return 0;
}
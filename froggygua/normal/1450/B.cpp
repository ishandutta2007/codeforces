#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
int T,n,k,x[N],y[N];
inline int Abs(int x){
	return x>=0?x:-x;
}
bool Solve(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		x[i]=read(),y[i]=read();
	}
	for(int i=1;i<=n;++i){
		bool ok=true;
		for(int j=1;j<=n;++j){
			if(Abs(x[i]-x[j])+Abs(y[i]-y[j])>k){
				ok=false;break;
			}
		}
		if(ok)return true;
	}
	return false;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"1\n":"-1\n");
	}
	return 0;
}
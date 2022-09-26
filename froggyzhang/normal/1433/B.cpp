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
int T,n,a[N];
int Solve(){
	n=read();
	int ans=0;
	for(int i=1,las=-1;i<=n;++i){
		a[i]=read();
		if(a[i]){
			if(~las)ans+=i-las-1;
			las=i;
		}
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}
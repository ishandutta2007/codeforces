#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 300010
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
	int mx=*max_element(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if((i>1&&a[i-1]<mx||i<n&&a[i+1]<mx)&&a[i]==mx)return i;
	}
	return -1;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		printf("%d\n",Solve());
	}
	return 0;
}
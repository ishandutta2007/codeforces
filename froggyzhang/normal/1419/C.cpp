#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2333
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
int T,n,a[N],x;
int Solve(){
	n=read(),x=read();
	int tot=0,same=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		same+=(a[i]==x);
		tot+=a[i];
	}
	if(same==n)return 0;
	if(tot==x*n||same)return 1;
	return 2;
}
int main(){
	T=read();
	while(T--){
		printf("%d\n",Solve());
	}
	return 0;
}
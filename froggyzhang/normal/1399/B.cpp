#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 233
const int inf=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;
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
int n,a[N],b[N],T;
ll Solve(){
	n=read();
	int ma=inf,mb=inf;
	ll ans=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		ma=min(ma,a[i]);
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
		mb=min(mb,b[i]);
	}
	for(int i=1;i<=n;++i){
		a[i]-=ma,b[i]-=mb;
		ans+=a[i]+b[i]-min(a[i],b[i]);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		printf("%I64d\n",Solve());
	}
	return 0;
}
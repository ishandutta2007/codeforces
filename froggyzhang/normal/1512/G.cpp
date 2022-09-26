#include<bits/stdc++.h>
using namespace std;
const int mx=10000000;
#define N 10000010
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
int T,n,c[N],ans[N];
int main(){
	for(int i=1;i<=mx;++i){
		for(int j=i;j<=mx;j+=i){
			c[j]+=i;
		}
		ans[i]=-1;
	}
	for(int i=mx;i>=1;--i){
		if(c[i]<=mx)ans[c[i]]=i;
	}
	T=read();
	while(T--){
		n=read();
		printf("%d\n",ans[n]);
	}
	return 0;
}
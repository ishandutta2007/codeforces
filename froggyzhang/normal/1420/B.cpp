#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
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
int cnt[32];
ll Solve(){
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i){
		for(int j=30;j>=0;--j){
			if((a[i]>>j)&1){
				++cnt[j];
				break;
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=30;++i){
		ans+=1LL*cnt[i]*(cnt[i]-1)/2;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		printf("%lld\n",Solve());
	}
	return 0;
}
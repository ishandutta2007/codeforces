#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,C,a[N],b[N];
int Solve(){
	n=read(),C=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<n;++i)b[i]=read();
	int now=0;
	ll ans=2e9,z=0;
	for(int i=1;i<=n;++i){
		ans=min(ans,z+(now>=C?0:(C-now+a[i]-1)/a[i]));
		if(now<b[i]){
			z+=(b[i]+a[i]-1-now)/a[i];
			now+=1LL*(b[i]+a[i]-1-now)/a[i]*a[i];
		}
		now-=b[i];++z;
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
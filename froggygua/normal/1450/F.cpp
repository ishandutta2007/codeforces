#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
int T,n,a[N],cnt[N];
int Solve(){
	int ans=0;
	++cnt[a[1]],++cnt[a[n]];
	for(int i=1;i<n;++i){
		if(a[i]==a[i+1])cnt[a[i]]+=2,++ans;
	}
	int t=max_element(cnt+1,cnt+n+1)-cnt;
	int res=0;
	for(int i=1;i<n;++i){
		if(a[i]^a[i+1]&&a[i]^t&&a[i+1]^t)++res;
	}
	while(cnt[t]>(ans+1)*2-cnt[t]+2){
		if(!res)return -1;
		++ans,--res;
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			cnt[i]=0;
		}
		printf("%d\n",Solve());
	}
	return 0;
}
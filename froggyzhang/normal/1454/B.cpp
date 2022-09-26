#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
int T,n,cnt[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)cnt[i]=0;
		int ans=-1;
		for(int i=1;i<=n;++i){
			int x=read();
			if(cnt[x])cnt[x]=-1;
			else cnt[x]=i;
		}
		for(int i=1;i<=n;++i){
			if(cnt[i]>=1){
				ans=cnt[i];break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
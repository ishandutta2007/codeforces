#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
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
int n,Q,cnt[2],a[N];
int main(){
	n=read(),Q=read();
	for(int i=1;i<=n;++i)a[i]=read(),++cnt[a[i]];
	while(Q--){
		int opt=read(),x=read();
		if(opt==1){
			--cnt[a[x]];
			a[x]^=1;
			++cnt[a[x]];
		}
		else{
			printf("%d\n",cnt[1]>=x);
		}
	} 
	return 0;
}
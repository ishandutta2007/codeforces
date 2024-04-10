#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 505
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
int n;
ll a[N],ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		for(int j=1;j<=i;++j){
			for(int k=1;k<=j;++k){
				ans=max(ans,a[i]|a[j]|a[k]);
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 500010
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
int n,a[N],myh,zyk;
ll ans;
inline int Abs(int x){
	return x>=0?x:-x;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		ans+=Abs(a[i]);
		if(a[i]>=0)myh=1;
		if(a[i]<=0)zyk=1;
	}
	if(n==1)return !printf("%d\n",a[1]);
	if(!zyk){
		ans-=2*(*min_element(a+1,a+n+1));
	}
	if(!myh){
		ans+=2*(*max_element(a+1,a+n+1));
	}
	printf("%lld\n",ans);
	return 0;
}
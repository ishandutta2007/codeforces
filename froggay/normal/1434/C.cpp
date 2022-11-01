#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
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
int T,a,b,c,d;
inline ll S(int x){
	return 1LL*x*(x+1)/2;
}
inline ll check(int x){
	ll t=min(x,c/d);
	return 1LL*a*(x+1)-1LL*(x-t)*b*c-1LL*S(t)*d*b;
}
ll Solve(){
	int ans=0,l=0,r=1e6+233;
	if(a>1LL*b*c)return -1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)>check(mid-1)){
			l=mid+1,ans=mid;
		}
		else{
			r=mid;
		}
	}
	return check(ans);
}
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read();
		printf("%lld\n",Solve());
	}
	return 0;
}
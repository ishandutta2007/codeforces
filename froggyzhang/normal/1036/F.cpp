#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mx=1e18+2;
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
int T,tot;
ll n,a[12345678];
bool isq(ll x){
	ll t=sqrt(x);
	while(t*t<x)++t;
	while(t*t>x)--t;
	if(t*t==x)return true;
	return false;
}
int main(){
	T=read();
	for(int i=3;i<=60;++i){
		for(int x=2;;++x){
			ll tmp=1;
			bool ok=true;
			for(int j=1;j<=i;++j){
				if(1.0L*tmp*x>mx){
					ok=false;
					break;
				}
				tmp*=x;
			}
			if(ok){
				if(!isq(tmp))a[++tot]=tmp;
			}
			else break;
		}
	}
	sort(a+1,a+tot+1);
	tot=unique(a+1,a+tot+1)-a-1;
	while(T--){
		n=read();
		ll t=sqrt(n);
		while(t*t<n)++t;
		while(t*t>n)--t;
		printf("%lld\n",n-t-(upper_bound(a+1,a+tot+1,n)-a-1));
	}
	return 0;
}
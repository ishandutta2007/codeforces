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
ll a,b,ans;
void _gcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(!b)return;
	ans+=a/b;
	a%=b;
	_gcd(a,b);
}
int main(){
	a=read(),b=read();
	_gcd(a,b);
	printf("%lld\n",ans);
	return 0;
}
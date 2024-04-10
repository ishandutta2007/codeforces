#include<iostream>
#include<cstdio>
#include<cstring>
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
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T;
ll l,r,m;
inline ll Abs(ll x){
	return x>=0?x:-x;
}
inline bool check(ll x,ll n){
	if(Abs(x*n-m)>r-l)return false;
	if(m>=x*n){
		printf("%I64d %I64d %I64d\n",x,l+m-x*n,l);
	}
	else{
		printf("%I64d %I64d %I64d\n",x,r-(x*n-m),r);
	}
	return true;
}
int main(){
	T=read();
	while(T--){
		l=read(),r=read(),m=read();
		for(register ll i=l;i<=r;++i){
			if(check(i,m/i+1))break;
			if(check(i,m/i))break;
		}
		
	}
	return 0;
}
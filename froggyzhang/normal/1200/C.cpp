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
ll n,m,q,sx,sy,ex,ey,u,v,s,e;
ll _gcd(ll a,ll b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
int main(){
	n=read(),m=read(),q=read();
	ll g=_gcd(n,m);
	u=n/g,v=m/g;
	while(q--){
		sx=read(),sy=read()-1,ex=read(),ey=read()-1;
		if(sx==1){
			s=sy/u;
		}
		else{
			s=sy/v;
		}
		if(ex==1){
			e=ey/u;
		}
		else{
			e=ey/v;
		}
		if(s==e){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
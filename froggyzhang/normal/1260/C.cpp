#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
inline int read(){
    int x=0,f=1;
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
ll a,b,k;
ll _gcd(ll a,ll b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
int main(){
	T=read();
	while(T--){
		a=read(),b=read(),k=read();
		if(k==1){
			printf("No\n");
			continue;
		}
		if(a>b)swap(a,b);
		ll g=_gcd(a,b);
		a/=g,b/=g;
		if((k-1)*a+1<b){
			printf("REBEL\n");
		}
		else{
			printf("OBEY\n");
		}
	}
	return 0;
}
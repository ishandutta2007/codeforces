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
ll x,y,a,b;
int main(){
	T=read();
	while(T--){
		x=read(),y=read();
		a=read(),b=read();
		if(2*a<=b){
			printf("%lld\n",(x+y)*a);
		}
		else{
			printf("%lld\n",(x+y-2*min(x,y))*a+min(x,y)*b);
		}
	}
	return 0;
}
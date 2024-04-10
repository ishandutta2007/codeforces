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
ll a,b,c,d,e,f,p;
int main(){
	a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
	if(e>f){
		p+=min(a,d)*e;
		d-=min(a,d);
		p+=min(min(b,c),d)*f;
	}
	else{
		p+=min(min(b,c),d)*f;
		d-=min(min(b,c),d);
		p+=min(a,d)*e;
	}
	cout<<p<<endl;
	return 0;
}
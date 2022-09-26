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
ll n,p,cnt;
ll Get(ll x){
	ll e=0;
	while(x){
		if(x&1)++e;
		x>>=1;
	}
	return e;
}
int main(){
	n=read(),p=read();
	while(n>0){
		cnt++;
		n-=p;
		if(n<=0)break;
		if(Get(n)<=cnt&&cnt<=n){
			cout<<cnt<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
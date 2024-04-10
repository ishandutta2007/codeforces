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
ll d,mod;
int main(){
	T=read();
	while(T--){
		d=read(),mod=read();
		if(d==1){
			cout<<1%mod<<endl;
			continue;
		}
		int x=1;
		ll ans=1;
		while(d>(1LL<<x)-1){
			ans=ans*((1LL<<(x-1))+1)%mod;
			++x;
		}
		ans=ans*((d-(1LL<<(x-1)))+2)%mod;
		cout<<(ans-1+mod)%mod<<endl;
	} 
	return 0;
}
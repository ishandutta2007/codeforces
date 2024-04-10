#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200020
const ll mod=998244353;
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
int n;
ll ans[N],p10;
int main(){
	n=read();
	p10=10;
	for(int i=n;i>=1;--i){
		ans[i]=p10*(n-i+1)%mod;
		p10=p10*10%mod;
	}
	for(int i=1;i<=n;++i){
		ans[i]=(ans[i]-2*ans[i+1]+ans[i+2]+mod)%mod;
		ans[i]=(ans[i]+mod)%mod;
	}
	for(int i=1;i<=n;++i){
		printf("%I64d ",ans[i]);
	}
	return 0;
}
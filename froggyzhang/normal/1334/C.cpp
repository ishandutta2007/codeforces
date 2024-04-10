#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 300030
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
int T,n;
ll a[N],b[N],c[N];
int main(){
	T=read();
	while(T--){
		n=read();
		ll tot=0;
		for(int i=0;i<n;++i){
			a[i]=read(),b[i]=read();
		}
		for(int i=0;i<n;++i){
			c[(i+1)%n]=a[(i+1)%n]-min(b[i],a[(i+1)%n]);
			tot+=c[(i+1)%n];
		}
		ll ans=4e18;
		for(int i=0;i<n;++i){
			ans=min(ans,tot+a[i]-c[i]);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
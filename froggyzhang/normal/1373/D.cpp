#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int T,a[N],n;
int main(){
	T=read();
	while(T--){
		n=read();
		ll ans=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(i&1)ans+=a[i];
		}
		ll s=0,mn=0,mx=0;
		for(int i=1;i<n;i+=2){
			s+=a[i+1]-a[i];
			mn=min(mn,s);
			mx=max(mx,s-mn);
		}
		s=0,mn=0;
		for(int i=2;i<n;i+=2){
			s+=a[i]-a[i+1];
			mn=min(mn,s);
			mx=max(mx,s-mn);
		}
		printf("%I64d\n",ans+mx);
	}
	return 0;
}
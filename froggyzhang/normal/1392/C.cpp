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
int T,n,a[N]; 
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		int las=a[1];
		ll ans=0;
		for(int i=2;i<=n;++i){
			if(a[i]<=a[i-1]){
				ans+=a[i-1]-a[i];
			}
			else if(a[i]>las){
				las=a[i];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
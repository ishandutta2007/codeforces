#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200020
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
int n,T,a[N]; 
ll k;
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		int mx=-1e9-1,mn=1e9+1;;
		for(int i=1;i<=n;++i){
			a[i]=read();
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
		}
		if(k&1){
			for(int i=1;i<=n;++i){
				printf("%d ",mx-a[i]);
			}
		}
		else{
			for(int i=1;i<=n;++i){
				printf("%d ",a[i]-mn);
			}
		}
		printf("\n");
	}
	return 0;
}
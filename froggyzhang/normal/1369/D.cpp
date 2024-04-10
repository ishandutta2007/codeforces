#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
const int mx=2000000;
#define N 2000200
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
int f[N][2],T,n;
int main(){
	f[1][1]=1,f[2][0]=f[2][1]=1;
	for(int i=3;i<=mx;++i){
		f[i][1]=(2LL*f[i-2][0]+f[i-1][0]+1)%mod;
		f[i][0]=(2LL*max(f[i-2][0],f[i-2][1])+max(f[i-1][0],f[i-1][1]))%mod;
	}
	T=read();
	while(T--){
		n=read();
		printf("%d\n",n==1?0:max(f[n-2][0],f[n-2][1])*4LL%mod);
	}
	return 0;
}
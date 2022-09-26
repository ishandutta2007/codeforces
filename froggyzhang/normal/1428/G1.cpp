#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 1000000
const int mx=999999;
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
int k,n,Q;
int f[6],ten[6];
ll dp[N]; 
const int t[10]={0,0,0,1,0,0,2,0,0,3};
int main(){
	k=read();
	for(int i=0;i<6;++i)f[i]=read();
	ten[0]=1;
	for(int i=1;i<6;++i)ten[i]=10*ten[i-1];
	memset(dp,~0x3f,sizeof(dp));
	dp[0]=0;
	for(int d=0;d<6;++d){
		int n=3*(k-1),p;
		for(p=1;n;p<<=1,p=min(n,p)){
			n-=p;
			for(int j=mx;j>=3LL*p*ten[d];--j){
				dp[j]=max(dp[j],dp[j-3*p*ten[d]]+1LL*p*f[d]);
			}
		}
	}
	for(int d=0;d<6;++d){
		for(int j=mx;j>=0;--j){
			for(int i=0;i<=9;++i){
				if(i*ten[d]<=j){
					dp[j]=max(dp[j],dp[j-i*ten[d]]+1LL*t[i]*f[d]);
				}
			}
		}
	}
	Q=read();
	while(Q--){
		int n=read();
		printf("%lld\n",dp[n]);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
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
int T,n,ans,a[N],dp[N];
int main(){
	T=read();
	while(T--){
		ans=1;
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			dp[i]=1;
		}
		for(int i=1;i<=n;++i){
			ans=max(ans,dp[i]); 
			for(int j=i+i;j<=n;j+=i){
				if(a[i]<a[j])dp[j]=max(dp[j],dp[i]+1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
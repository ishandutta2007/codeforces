#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 505
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
int n,a[N],num[N][N],dp[N][N];
int main(){
	n=read();
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		a[i]=read();
		num[i][i]=a[i];
		dp[i][i]=1;
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;++l){
			int r=l+len-1;
			for(int k=l;k<r;k++){
				if(num[l][k]==num[k+1][r]&&num[l][k]){
					num[l][r]=num[l][k]+1;
					dp[l][r]=1;
					break;
				}
			}
			if(!num[l][r]){
				for(int k=l;k<r;k++){
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2020
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
int n,t;
double p,dp[N][N];
int main(){
	n=read();
	scanf("%lf",&p);
	t=read();
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t;j++){
			dp[i][j]=(1-p)*dp[i][j-1]+p*(dp[i-1][j-1]+1);
		} 
	}
	printf("%.6lf",dp[n][t]);
	return 0;
}
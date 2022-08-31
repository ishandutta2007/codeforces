#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,x,y;
double dp[1002][1002];
int main(){
	n=read(),m=read(),x=read(),y=read();
	for(re int i=n-1;i>=x;--i)
	for(re int j=1;j<=50;++j)
		if(m==1)dp[i][1]=(dp[i][1]+dp[i+1][1])/2.0+1;
		else{
			dp[i][1]=(dp[i][1]+dp[i+1][1]+dp[i][2])/3.0+1;
			dp[i][m]=(dp[i][m]+dp[i][m-1]+dp[i+1][m])/3.0+1;
			for(re int k=2;k<m;++k)dp[i][k]=(dp[i][k]+dp[i][k-1]+dp[i][k+1]+dp[i+1][k])/4.0+1;
		}
	printf("%.6lf",dp[x][y]);
}
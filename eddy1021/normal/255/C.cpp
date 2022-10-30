#include <stdio.h>
#define N 4010
int n,bx[N],i,j,ans,pre,dp[N][N];
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int max( int x , int y ){ return x>y?x:y; }
int main(){
	n=getint();
	for( i=1;i<=n;i++ ) bx[i]=getint();
	for( i=1;i<=n;i++ )
		for( j=pre=0;j<i;j++ ){
			dp[i][j]=dp[j][pre]+1;
			if( bx[i]==bx[j] ) pre=j;
			ans = max( ans , dp[i][j] );
		}
	printf("%d\n",ans);
}
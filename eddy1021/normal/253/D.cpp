#include <stdio.h>
#include <string.h>
#define N 410
int n,m,k,sum[N][N],can[N],s,t,tmp; char c[N][N];
long long ans;
int main(){

	FILE *fin,*fout;
	fin = freopen("input.txt","r",stdin);
	fout = freopen("output.txt","w",stdout);

	scanf("%d %d %d\n",&n,&m,&k);
	for( int i=1;i<=n;i++ ) gets(c[i]+1);
	for( int i=1;i<=n;i++ )
		for( int j=1;j<=m;j++ ){
			sum[i][j]=sum[i-1][j];
			if( c[i][j]=='a' ) sum[i][j]++;
		}
	for( int i=1;i<n;i++ ) for( int j=i+1;j<=n;j++ ){
		memset( can , 0 , sizeof(can) );
		s=1; tmp=sum[j][1]-sum[i-1][1];
		if( c[i][1]==c[j][1] ) can[c[i][1]]++;
		for( t=2;t<=m;t++ ){
			tmp+=sum[j][t]-sum[i-1][t];
			while( tmp>k ){
				tmp-=sum[j][s]-sum[i-1][s];
				if( c[i][s]==c[j][s] ) can[c[i][s]]--;
				s++;
			}
			if( c[i][t]==c[j][t] ){
				if( s<t ) ans+=can[c[i][t]];
				can[c[i][t]]++;
			}
		}
	}
	printf("%I64d\n",ans);

	fclose(fin); fclose(fout);
}
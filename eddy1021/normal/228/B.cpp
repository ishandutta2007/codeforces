#include <stdio.h>
#define N 51
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define max(x,y) (x>y?x:y)
int a[N][N],b[N][N],na,nb,ma,mb,maxsum,maxx,maxy,tmp;
int main(){
	scanf("%d %d ",&na,&ma); char c=getchar();
	FOR(i,0,na) FOR(j,0,ma){
		while( c<'0'||c>'1' ) c=getchar();
		a[i][j]=c-'0'; c=getchar();
	} scanf("%d %d ",&nb,&mb); maxsum=-1;
	FOR(i,0,nb) FOR(j,0,mb){
		while( c<'0'||c>'1' ) c=getchar();
		b[i][j]=c-'0'; c=getchar();
	}
	FOR(x,-55,55) FOR(y,-55,55){
		tmp=0;
		for( int i=max(-x,0);i<na&&i+x<nb;i++ )
			for( int j=max(-y,0);j<ma&&j+y<mb;j++ )
				tmp+=a[i][j]*b[i+x][j+y];
		if( tmp>maxsum||maxsum==-1 ){
			maxsum = tmp; maxx=x; maxy=y;
		}
	}
	printf("%d %d\n",maxx,maxy);
}
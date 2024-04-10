#include <stdio.h>
#define N 3
char ans[N][N];
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int tmp;
bool cn( int ti , int tj ){
	if( ti<0 || tj<0 || ti>2 || tj>2 ) return 0; return 1;
}
int di[]={0,0,1,0,-1},dj[]={0,1,0,-1,0};
int main(){
	for( int i=0;i<N;i++ )
		for( int j=0;j<N;j++ ){
			tmp = getint();
			if( tmp%2 ){
				for( int k=0;k<5;k++ )
					if( cn( i+di[k] , j+dj[k] ) ) ans[i+di[k]][j+dj[k]] ^= 1;
			}
		}
	for( int i=0;i<N;puts(""),i++ ) for( int j=0;j<N;j++ ) putchar((!ans[i][j])+'0');
}
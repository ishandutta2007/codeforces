#include <stdio.h>
int bx[4][4];
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	for( int i=0;i<3;i++ ) for( int j=0;j<3;j++ ) bx[i][j]=getint();
	bx[0][0] = ( bx[2][0] + bx[2][0] + bx[2][1] - bx[0][1] ) / 2;
	bx[2][2] = bx[0][2] + bx[2][0] - bx[0][0];
	bx[1][1] = bx[0][0] + bx[0][1] + bx[0][2] - bx[1][0] - bx[1][2];
	for( int i=0;i<3;i++ ) for( int j=0;j<3;j++ )
		printf("%d%c",bx[i][j],j==2?'\n':' ');
}
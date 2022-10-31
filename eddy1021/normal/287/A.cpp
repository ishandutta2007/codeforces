#include <stdio.h>
#include <string.h>
#define N 10
char c[ N ];
bool kd[ N ][ N ],cn;
bool check(){
	for( int i=1;i<=3;i++ )
		for( int j=1;j<=3;j++ )
			if( kd[i][j] == kd[i+1][j] &&
				kd[i+1][j] == kd[i][j+1] &&
				kd[i][j+1] == kd[i+1][j+1] )
					return 1;
	return 0;
}
void process(){
	if( check() ){ cn = 1; return; }
	for( int i=1;i<=4;i++ )
		for( int j=1;j<=4;j++ ){
			kd[i][j] = 1 - kd[i][j];
			if( check() ){ cn = 1; return ; }
			kd[i][j] = 1 - kd[i][j];
		}
}
int main(){
	for( int i=1;i<=4;i++ ){
		scanf("%s",c+1);
		for( int j=1;j<=4;j++ ) kd[i][j] = c[j]=='#'?1:0;
	}
	process(); puts(cn?"YES":"NO");
}
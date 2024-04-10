#include <stdio.h>
#include <string.h>
#define N 200010
char c[N];
int a , f , i , l , ans;
int main(){
	scanf("%d%s",&l,c);
	for( int j=0;j<l;j++ )
		if( c[j] == 'A' ) a ++;
		else if( c[j] == 'F' ) f ++;
		else if( c[j] == 'I' ) i ++;
	for( int j=0;j<l;j++ ){
		if( c[j] == 'A' ){
			if( !i ) ans ++;
		}else if( c[j] == 'I' ){
			i --;
			if( !i ) ans ++;
			i ++;
		}
	}
	printf("%d\n",ans);
}
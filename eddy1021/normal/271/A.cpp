#include <stdio.h>
int y;
int main(){
	scanf("%d",&y);
	while( ++y ){
		int	bx[10]={},tmp=y,cnt=0;
		while( tmp ) bx[ tmp%10 ]++,tmp /= 10;
		for( int i=0;i<10;i++ ) if( bx[i] ) cnt++;
		if( cnt==4 ){
			return printf("%d\n",y),0;
		}
	}
}
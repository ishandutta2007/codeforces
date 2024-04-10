#include <stdio.h>
int n,t; char c[60];
int main(){
	scanf("%d %d",&n,&t); scanf("%s",c);
	while( t-- ){
		for( int i=1;i<n;i++ )
			if( c[i-1]=='B' && c[i]=='G' )
				c[i-1]='G',c[i]='B',i++;
	}
	puts(c);
}
#include <stdio.h>
int n,m;
int main(){

	FILE *fin,*fout;
	fin = freopen("input.txt","r",stdin);
	fout = freopen("output.txt","w",stdout);

	scanf("%d%d",&n,&m);
	if( n>m ){
		n-=m; while( m-- ) putchar('B'),putchar('G');
		while( n-- ) putchar('B'); putchar('\n');	
	}else{
		m-=n; while( n-- ) putchar('G'),putchar('B');
		while( m-- ) putchar('G'); putchar('\n');
	}

	fclose(fin); fclose(fout);
}
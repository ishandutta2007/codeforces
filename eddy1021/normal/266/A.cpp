#include <stdio.h>
int n,cnt; char c[60];
int main(){
	scanf("%d",&n); scanf("%s",c);
	for( int i=1;i<n;i++ ) if( c[i-1]==c[i] ) cnt++;
	printf("%d\n",cnt);
}
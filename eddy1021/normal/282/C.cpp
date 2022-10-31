#include <stdio.h>
#include <string.h>
#define L 1000010
char c1[L],c2[L];
int cnt1,cnt2,l1,l2;
int main(){
	scanf("%s",c1); scanf("%s",c2);
	l1 = strlen( c1 ); l2 = strlen( c2 );
	if( l1 != l2 ) return puts("NO");
	for( int i=0;c1[i];i++ ) if( c1[i]=='1' ){ cnt1 = 1; break; }
	for( int i=0;c2[i];i++ ) if( c2[i]=='1' ){ cnt2 = 1; break; }
	if( (cnt1>0) == (cnt2>0) ) return puts("YES");
	puts("NO");
}
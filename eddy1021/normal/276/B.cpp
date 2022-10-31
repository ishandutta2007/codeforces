#include <stdio.h>
#define N 26
#define L 1010
int cnt[ N ],cnto;
char c[ L ];
bool test(){
	if( cnto < 2 ) return 0; cnto --;
	return cnto%2;
}
int main(){
	scanf("%s",c);
	for( int i=0;c[i];i++ ) cnt[ c[i]-'a' ] ++;
	for( int i=0;i<N;i++ ) if( cnt[i]%2 ) cnto ++;
	puts(test()?"Second":"First");
}
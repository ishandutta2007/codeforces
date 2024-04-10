#include <stdio.h>
#include <string.h>
bool now[256];
char c[101];
int main(){
	int cnt=0; scanf("%s",c);
	for( int i=0;c[i];i++ ){
		if( !now[ c[i] ] ) now[ c[i] ]=true,cnt++;
	}
	puts(!(cnt&1)?"CHAT WITH HER!":"IGNORE HIM!");
	return 0;
}
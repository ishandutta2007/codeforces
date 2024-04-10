#include <stdio.h>
#include <string.h>
#define L 52
char r[L],i[L];
int now , lr , li , on;
int main(){
	scanf("%s %s",r,i); now = 0;
	lr = strlen(r); li = strlen(i);
	for( int j=0;j<li;j++ ){
		if( i[j]==r[now] ) now++;
		if( now==lr ) break;
	}
	printf("%d\n",now+1);
}
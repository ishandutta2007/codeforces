#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,k,cnt,tcnt,tmp;
int main(){
	n = getint(); k = getint();
	while( n-- ){
		tmp = getint(); tcnt = 0;
		while( tmp ){
			if( tmp%10 == 4 || tmp%10 == 7 ) tcnt++; tmp /= 10;
		}
		if( tcnt <= k ) cnt++;
	}
	printf("%d\n",cnt);
}
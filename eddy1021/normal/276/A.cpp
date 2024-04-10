#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int max,n,k,fi,ti,tmp;
int val(){
	if( ti <= k ) return fi;
	return fi - ( ti - k );
}
int main(){
	n = getint(); k = getint();
	fi = getint(); ti = getint();
	max = val(); while( --n ){
		fi = getint(); ti = getint();
		tmp = val(); if( tmp > max ) max = tmp;
	}
	printf("%d\n",max);
}
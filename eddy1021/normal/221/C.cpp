#include <stdio.h>
#include <algorithm>
#define maxN 100001
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,cnt,bx[maxN],tmp[maxN];
int main(){
	n=getint(); cnt=0;
	for( int i=0;i<n;tmp[i]=bx[i]=getint(),i++ );
	std::sort( tmp , tmp+n );
	for( int i=0;i<n&&cnt<3;i++ ) if( tmp[i]!=bx[i] ) cnt++;
	puts(cnt<3?"YES":"NO");
}
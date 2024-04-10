#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define N 1000010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
struct XD{
	int a,g,no;
}bx[N];
bool cmp( XD x , XD y ){ return x.a < y.a; }
int n,dpa[N],dpg[N]; char ans[ N ];
int main(){
	n = getint(); ans[ n+1 ] = '\0';
	for( int i=1;i<=n;i++ ){
		bx[i].a = getint(); bx[i].g = getint(); bx[i].no = i;
	}
	std::sort( bx+1 , bx+n+1 , cmp );
	for( int i=1;i<=n;i++ )
		dpa[i] = dpa[i-1] + bx[i].a;
	for( int i=n;i;i-- )
		dpg[i] = dpg[i+1] + bx[i].g;
	for( int i=0;i<=n;i++ )
		if( abs( dpa[i] - dpg[i+1] ) <= 500 ){
			for( int j=1;j<=i;j++ ) ans[ bx[j].no ] = 'A';
			for( int j=i+1;j<=n;j++ ) ans[ bx[j].no ] = 'G';
			return puts(ans+1),0;
		}
	puts("-1");
}
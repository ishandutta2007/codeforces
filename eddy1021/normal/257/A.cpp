#include <stdio.h>
#include <algorithm>
#define N 51
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,m,k,v[N],cnt,now;
int main(){
	n = getint(); m = getint(); k = getint(); 
	for( int i=0;i<n;i++ ) v[i] = getint(), v[i] --;
	std::sort( v , v+n ); cnt = 0; now = n-1;
	while( k<m && now>=0 ){
		k += v[now--]; cnt++;
	}
	if( k<m ) return puts("-1"),0;
	else printf("%d\n",cnt);
}
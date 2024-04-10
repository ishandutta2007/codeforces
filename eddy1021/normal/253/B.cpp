#include <stdio.h>
#include <algorithm>
#define N 100010
#define inf 1<<30
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int min( int x , int y ){ return x<y?x:y; }
int bx[N],i,n,ans,s,t,bdr,waste;
int main(){

	FILE *fin,*fout;
	fin = freopen("input.txt","r",stdin);
	fout = freopen("output.txt","w",stdout);

	n=getint(); ans=inf;
	for( i=0;i<n;i++ ) bx[i]=getint();
	std::sort( bx , bx+n );
	for( s=0,t=0;s<n;s++ ){
		bdr = bx[s]<<1;
		while( t<n&&bx[t]<=bdr ) t++; t--;
		waste=n-(t-s+1);
		ans = min( ans , waste );
	}
	printf("%d\n",ans);

	fclose(fin); fclose(fout);
}
#include <stdio.h>
#include <algorithm>
#define N 300010
struct XD{ int n,no; }bx[N<<1];
struct XDD{ int f,s; }ans[N];
int n,atp,m;
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
bool cmp( XD x , XD y ){ return x.n<y.n; }
int main(){

	FILE *fin,*fout;
	fin = freopen("input.txt","r",stdin);
	fout = freopen("output.txt","w",stdout);

	n=getint(); m=n<<1;
	for( int i=0;i<m;i++ ) bx[i].n=getint(),bx[i].no=i+1;
	std::sort( bx , bx+m , cmp );
	for( int i=0;i<n;i++ ){
		if( bx[i<<1].n!=bx[(i<<1)+1].n ) return puts("-1"),0;
		ans[i].f=bx[i<<1].no;
		ans[i].s=bx[(i<<1)+1].no;
	}
	for( int i=0;i<n;i++ ) printf("%d %d\n",ans[i].f,ans[i].s);

	fclose(fin); fclose(fout);
}
#include <stdio.h>
#include <algorithm>
#define d double
#define N 50010
d getint(){
	d x = 0.0; char c=getchar();
	while( c<'0'||c>'9' ) c = getchar();
	while(c>='0'&&c<='9') x *= 10.0 , x += (c-'0') , c=getchar();
	return x;
}
struct XD{ d l,p; }bx[N];
bool cmp( XD x , XD y ){ return x.p * x.l * (1.0 - y.p) > y.p * y.l * (1.0 - x.p); }
int n; d ans,pre;
void input(){
	scanf("%d",&n);
	for( int i=0;i<n;i++ )
		bx[i].l = getint(),bx[i].p = getint(),bx[i].p /= 100;
	std::sort( bx , bx+n , cmp );
}
void process(){
	for( int i=0;i<n;i++ ){
		ans += bx[i].l;
		ans += pre * ( 1.00-bx[i].p );
		pre += bx[i].p * bx[i].l;
	}
}
int main(){
	input(); process();
	printf("%.20lf\n",ans);
}
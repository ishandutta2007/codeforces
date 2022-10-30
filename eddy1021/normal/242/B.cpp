#include <stdio.h>
#include <algorithm>
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
struct XD{
    int l,r,no;
}bx[100010]; int n;
bool cmp( XD x , XD y ){ if( x.l!=y.l ) return x.l<y.l; return x.r>y.r; }
int main(){
    n=getint();
    for( int i=0;i<n;i++ ) bx[i].l=getint(),bx[i].r=getint(),bx[i].no=i+1;
    std::sort( bx , bx+n , cmp );
    for( int i=1;i<n;i++ ) if( bx[i].r>bx[0].r ) return puts("-1"),0;
    printf("%d\n",bx[0].no);
}
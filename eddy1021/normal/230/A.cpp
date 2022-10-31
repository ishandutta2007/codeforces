#include <stdio.h>
#include <algorithm>
#define FOR(i,j,k) for( int i=j;i<k;i++ )
int s,n;
struct XD{
    int xi,yi;
}dg[1001];
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
bool ans(){
    FOR(i,0,n){
        if( s<=dg[i].xi ) return 0;
        s+=dg[i].yi;
    }
    return 1;
}
bool cmp( XD x , XD y ){
    if( x.xi!=y.xi ) return x.xi<y.xi;
    return x.yi>y.yi;
}
int main(){
    while( scanf("%d%d",&s,&n)==2 ){
        FOR(i,0,n) dg[i].xi=getint(),dg[i].yi=getint();
        std::sort( dg , dg+n , cmp );
        puts(ans()?"YES":"NO");
    }
    return 0;
}
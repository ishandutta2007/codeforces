#include <stdio.h>
#define N 1<<20
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int b[N],n,bx[N],t,i,j,ano,ans;
int main(){
    n=getint(); while( n-- ){
        t=getint(); bx[j=i++]=t; b[t]=1; ano=0;
        while( j-- ){
            ano|=bx[j]; b[t|ano]=1;
            if( !(t&~ano) ) break;
        }
    }for( i=0;i<N;i++ ) ans+=b[i]; printf("%d\n",ans);
}
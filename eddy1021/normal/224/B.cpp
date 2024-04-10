#include <stdio.h>
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int a[100010],n,k,tf,tt,tl,nf,nl,nc,u[100010];
int main(){
    n=getint(); k=getint(); tf=tt=-2; tl=1000000; nf=nc=nl=0;
    for( int i=0;i<n;a[i]=getint(),i++ );
    for( int i=0;i<n;i++ ){
        if( !u[ a[i] ] ) nc++,u[a[i]]++; else u[a[i]]++; nl++;
        while( u[ a[nf] ]>1 ) u[ a[nf] ]--,nf++,nl--;
        if( nc==k&&nl<tl ) tf=nf,tt=i,tl=nl;
    }
    printf("%d %d\n",tf+1,tt+1);
    return 0;
}
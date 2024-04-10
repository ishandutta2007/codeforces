#include <stdio.h>
int main(){
    int n,bd,i; scanf("%d",&n);
    if( n&1 ) { puts("-1"); return 0; }
    for( i=1,bd=n>>1;i<=bd;i++ ) printf("%d %d ",i<<1,(i<<1)-1);
    puts(""); return 0;
}
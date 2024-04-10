#include <stdio.h>
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int b[60],n,k,ans,bd;
int main(){
    n=getint(); k=getint();
    for( int i=0;i<n;b[i]=getint(),i++ ); bd=b[k-1];
    for( int i=0;i<n;i++ ) if( b[i]>=bd&&b[i] ) ans++; else break;
    printf("%d\n",ans); return 0; 
}
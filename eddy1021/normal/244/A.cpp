#include <stdio.h>
#define N 40
int n,k,tp[N],get[N][N],tmp,now;
bool usd[N*N];
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int main(){
    n=getint(); k=getint(); now=1;
    for( int i=1;i<=k;i++ ) tmp=getint(),get[i][tp[i]++]=tmp,usd[tmp]=true;
    for( int i=1;i<=n*k;i++ ) if( !usd[i] ){
        while( tp[now]>=n ) now++; get[now][tp[now]++]=i;
    }
    for( int i=1;i<=k;putchar('\n'),i++ ) for( int j=0;j<n;j++ )
    { printf("%d",get[i][j]); if( j!=n-1 ) putchar(' '); }
}
#include <stdio.h>
int x[6],a[6],ans;
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c=='-' ) tmp=-1,c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int main(){
    for( int i=0;i<6;x[i]=getint(),i++ );
    for( int i=0;i<6;a[i]=getint(),i++ ); ans=0;
    if( x[1]<0 ) ans+=a[0]; if( x[1]>x[4] ) ans+=a[1];
    if( x[2]<0 ) ans+=a[2]; if( x[2]>x[5] ) ans+=a[3];
    if( x[0]<0 ) ans+=a[4]; if( x[0]>x[3] ) ans+=a[5];
    printf("%d\n",ans);
}
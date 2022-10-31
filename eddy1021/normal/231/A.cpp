#include <stdio.h>
int n,cnt,x,sum,i;
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int main(){
    scanf("%d",&n);
    while( n-- ){
        for( i=0,sum=0;i<3;i++ ) x=getint(),sum+=x;
        if( sum>1 ) cnt++;
    }
    printf("%d\n",cnt); return 0;
}
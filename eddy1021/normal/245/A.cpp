#include <stdio.h>
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
int a[2],b[2],n,k,x,y;
int main(){
    n=getint(); while( n-- ){
        k=getint(); x=getint(); y=getint();
        if(k==1) a[0]+=x,a[1]+=y;
        else b[0]+=x,b[1]+=y;
    }puts(a[0]>=a[1]?"LIVE":"DEAD");
    puts(b[0]>=b[1]?"LIVE":"DEAD");
}
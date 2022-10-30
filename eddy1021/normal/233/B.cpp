#include <stdio.h>
#include <math.h>
#define ll long long
ll getl(){
    ll x=0LL; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
ll n,tmp,cnt,tt,ta,ans;
bool test(){
    n=getl(); tmp=sqrt(n); tmp-=100;
    for( int i=0;i<101;i++,tmp++ ){
        if( tmp<=0 ) continue;
        ans=tt=tmp; ta=0; while( tt ) ta+=(tt%10),tt/=10;
        tt = tmp*(tmp+ta); if( tt==n ) { printf("%d\n",ans); return 1; };
    }
    return 0;
}
int main(){
    if( !test() ) puts("-1"); return 0;
}
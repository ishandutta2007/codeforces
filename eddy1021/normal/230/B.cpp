#include <stdio.h>
#include <math.h>
#define maxN 1100
#define ll long long
bool p[maxN];
ll pl[500],pt=-1,n,q,tmp,tmp2; long double lb1,lb2;
void build(){
    for( ll i=2;i<maxN;i++ ) if( !p[i] ){ pl[++pt]=i;
        for( ll j=2;i*j<maxN;p[i*j]=true,j++ );
    }
}
ll getl(){
    ll x=0LL; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10LL,x+=(c-'0'),c=getchar();
    return x;
}
bool test(){
    q = getl(); if(q==1) return 0; lb1 = q;
    lb2 = sqrt(lb1); tmp = lb2; lb1 = tmp;
    if( lb1!=lb2 ) return 0;
    tmp2 = sqrt(lb1);
    for( int i=0;pl[i]<=tmp2;i++ ) if( !(tmp%pl[i]) ) return 0;
    return 1;
}
int main(){
    build(); n=getl(); while(n--) puts(test()?"YES":"NO");
    return 0;
}
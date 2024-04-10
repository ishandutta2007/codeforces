#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define mod 1000000007
#define ll long long
ll getint(){
    ll x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
ll a , b;
void init(){
    a = getint(); b = getint();
}
void solve(){
    ll ans1 , ans2 , ans3;
    ans1 = ( ( a * ( a + 1 ) ) / 2 ) % mod;
    ans1 = ( ans1 * b ) % mod;
    
    ans3 = ( ( b * ( b - 1 ) ) / 2 ) % mod;
    ans1 = ( ans1 * ans3 ) % mod;

    ans2 = ( ( b * ( b - 1 ) ) / 2 ) % mod;
    ans2 = ( ans2 * a ) % mod;
    ans1 = ( ans1 + ans2 ) % mod;
    printf( "%I64d\n" , ans1 );
}
int main(){
    init();
    solve();
}
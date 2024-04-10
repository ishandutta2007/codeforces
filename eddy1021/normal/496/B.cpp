#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
#define N 1010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n;
string ts , s[ N ];
string cal( int st ){
    string stmp;
    int dlt = ( 10 - ( ts[ st ] - '0' ) );
    for( int i = st ; i < st + n ; i ++ )
        stmp += ( ts[ i % n ] - '0' + dlt ) % 10 + '0';
    return stmp;
}
void init(){
    n = getint();
    cin >> ts;
    for( int i = 0 ; i < n ; i ++ )
        s[ i ] = cal( i );
}
void solve(){
    sort( s , s + n );
    cout << s[ 0 ] << endl;
}
int main(){
    init();
    solve();
}
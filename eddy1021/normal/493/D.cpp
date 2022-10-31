#include <bits/stdc++.h>
using namespace std;
int n;
void init(){
    scanf( "%d" , &n );
}
void solve(){
    if( n & 1 ) puts( "black" );
    else puts( "white\n1 2" );
}
int main(){
    init();
    solve();
}
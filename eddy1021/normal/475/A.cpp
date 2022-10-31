#include <bits/stdc++.h>
using namespace std;
#define N 10010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int t , n , m , a[ N ];
char c[ 10 ][ 100 ] = {
"+------------------------+" ,
"|#.#.#.#.#.#.#.#.#.#.#.|D|)" ,
"|#.#.#.#.#.#.#.#.#.#.#.|.|" ,
"|#.......................|" ,
"|#.#.#.#.#.#.#.#.#.#.#.|.|)" ,
"+------------------------+"
};
void init(){
    n = getint();
}
int x , y;
void nxt(){
    if( x == 2 && y == 1 ) x ++;
    else if( x == 4 ) x = 1 , y += 2;
    else if( x == 2 ) x += 2;
    else x ++;
}
void solve(){
    x = y = 1;
    while( n -- ){
        c[ x ][ y ] = 'O';
        nxt();
    }
    for( int i = 0 ; i < 6 ; i ++ ) puts( c[ i ] );
}
int main(){
    init();
    solve();
}
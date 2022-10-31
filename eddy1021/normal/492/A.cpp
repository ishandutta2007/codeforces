#include <bits/stdc++.h>
using namespace std;
int n , ans;
int main(){
    scanf( "%d" , &n );
    int nd = 0;
    for( int i = 1 ; ; i ++ ){
        nd += i;
        if( n >= nd ) n -= nd , ans = i;
        else break;
    }
    printf( "%d\n" , ans );
}
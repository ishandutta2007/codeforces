#include <bits/stdc++.h>
using namespace std;
int a , b , c;
int main(){
    scanf( "%d%d%d" , &a , &b , &c );
    int ans = a + b + c;
    if( a + b * c > ans ) ans = a + b * c;
    if( a * b * c > ans ) ans = a * b * c;
    if( a * b + c > ans ) ans = a * b + c;
    if( ( a + b ) * c > ans ) ans = ( a + b ) * c;
    if( a * ( b + c ) > ans ) ans = a * ( b + c );
    printf( "%d\n" , ans );
}
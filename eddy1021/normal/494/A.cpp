#include <bits/stdc++.h>
using namespace std;
#define N 100010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int len , tot , cnt;
char c[ N ];
void init(){
    scanf( "%s" , c );
    len = strlen( c );
    for( int i = 0 ; i < len ; i ++ )
        if( c[ i ] == '(' ) tot ++;
        else if( c[ i ] == ')' ) tot --;
        else cnt ++;
}
vector<int> ans;
void solve(){
    if( tot <= 0 ){
        puts( "-1" );
        return;
    }
    int left = 0 , right = 0;
    for( int i = len - 1 ; i >= 0 ; i -- ){
        if( c[ i ] == '(' ) left ++;
        else if( c[ i ] == ')' ) right ++;
        else{
            cnt --;
            int tk = tot - cnt;
            right += tk; tot -= tk;
            ans.push_back( tk );
        }
        if( left > right ){
            puts( "-1" );
            return;
        }
    }
    if( left != right || tot > 0 ) puts( "-1" );
    else{
        for( int i = (int)ans.size() - 1 ; i >= 0 ; i -- )
            printf( "%d\n" , ans[ i ] );
    }
}
int main(){
    init();
    solve();
}
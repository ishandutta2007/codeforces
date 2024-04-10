#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF 1023456789
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
int getint(){
    int x=0,tmp=1; char tc=getchar();
    while( (tc<'0'||tc>'9')&&tc!='-' ) tc=getchar();
    if( tc == '-' ) tc=getchar() , tmp = -1;
    while(tc>='0'&&tc<='9') x*=10,x+=(tc-'0'),tc=getchar();
    return x*tmp;
}
int __ = 1;
/*********default*********/
#define L 1000010
char c[ L ];
int ansm , ansc , len;
bool tag[ L ];
void build(){

}
void init(){
    ansm = 0; ansc = 1;
    scanf( "%s" , c );
    len = strlen( c );
}
void update( int tans ){
    if( tans > ansm ) ansm = tans , ansc = 1;
    else if( tans == ansm ) ansc ++;
}
priority_queue< pair<int,PII> > heap;
deque<int> v;
void solve(){
    for( int i = 0 ; i < len ; i ++ )
        if( c[ i ] == '(' ) v.PB( i );
        else{
            if( (int)v.size() > 0 ){
                heap.push( MP( v.back() - i , MP( v.back() , i ) ) );
                v.pop_back();
            }
        }
    while( heap.size() ){
        pair<int,PII> tp = heap.top(); heap.pop();
        if( tp.FI == -1 || ( tag[ tp.SE.FI + 1 ] && tag[ tp.SE.SE - 1 ] ) )
            tag[ tp.SE.FI ] = tag[ tp.SE.SE ] = true;
    }
    int tlen = 0;
    for( int i = 0 ; i < len ; i ++ )
        if( tag[ i ] ) tlen ++ , update( tlen );
        else tlen = 0;
    printf( "%d %d\n" , ansm , ansc );
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
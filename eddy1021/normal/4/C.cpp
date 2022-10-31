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
int n;
map< string , int > M;
void build(){

}
void init(){
    n = getint();
}
void solve(){
    while( n -- ){
        string stmp; cin >> stmp;
        if( M.count( stmp ) > 0 ){
            cout << stmp << M[ stmp ] << endl;
            M[ stmp ] ++;
        }else{
            M[ stmp ] = 1;
            puts( "OK" );
        }
    }
}
int main(){
    build();
//    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
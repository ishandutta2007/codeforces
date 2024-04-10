#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
#define mod9 1000000009
#define mod7 1000000007
#define N 100010
int getint(){
    int x=0,tmp=1; char c=getchar();
    while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
    if( c == '-' ) c=getchar() , tmp = -1;
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x*tmp;
}
int n , ans;
map<int,int> M , M2;
typedef map<int,int>::iterator mi;
void init(){
    n = getint();
    for( int i = 1 ; i <= n ; i ++ ){
        int up , down;
        up = getint();
        down = getint();
        M[ up ] ++;
        M2[ up ] ++;
        if( up != down ) M2[ down ] ++;
    }
    ans = -1;
}
void solve(){
    int hlf = ( n / 2 ) + ( n % 2 );
    for( mi it = M2.begin() ; it != M2.end() ; it ++ )
        if( it -> second >= hlf ){
            int tans = hlf - M[ it->first ];
            if( tans < 0 ) tans = 0;
            if( ans == -1 || tans < ans )
                ans = tans;
        }
    printf( "%d\n" , ans );
}
int main(){
    init();
    solve();
}
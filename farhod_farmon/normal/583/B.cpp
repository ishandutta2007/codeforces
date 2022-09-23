#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int ans, f, a, b[1001];
bool used[1001];

void g( int x )
{
    if( x == 0 ){
        for( int i = 1; i <= a; i++ ){
            if( f >= b[i] )b[i] = 0;
            if( !b[i] && !used[i] ){
                used[i] = true;
                f++;
            }
        }
    }
    else{
        for( int i = a; i >= 1; i-- ){
            if( f >= b[i] )b[i] = 0;
            if( !b[i] && !used[i] ){
                used[i] = true;
                f++;
            }
        }
    }
}

bool B()
{
    for( int i = 1; i <= a; i++ ){
        if( b[i] )return false;
    }
    return true;
}

int main()
{
    cin >> a;
    for( int i = 1; i <= a; i++ ) cin >> b[i];
    while(!B()){
        g(ans % 2);
        ans++;
    }
    cout << max(ans - 1, 0) << endl;
}
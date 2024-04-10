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
#include <iomanip>

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

string s;
int i, j, cnt;

int main()
{
    cin >> s;
    for( i = s.size() - 1; i > 0; i-- ){
        if( s[i] == '0' )cnt++;
        else{
            cnt++;
            for( j = i; j > 0; j-- ){
                if( s[j] == '0' )break;
                cnt++;
            }
            s[j] = '1';
            i = j + 1;
            if( !j )cnt++;
        }
    }
    cout << cnt << endl;
}
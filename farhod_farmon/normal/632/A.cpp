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

using namespace std;

lli p, n, x = 1, cnt, i;
string s[44];

int main()
{
    cin >> n >> p;
    for( i = 1; i <= n; i++ )cin >> s[i];
    for( i = n - 1; i >= 1; i-- ){
        if( s[i] == "half" ){
            cnt += x * p;
            x *= 2;
        }
        else{
            cnt += x * p + p / 2;
            x *= 2;
            x += 1;
        }
    }
    cout << cnt + p / 2 << endl;
}
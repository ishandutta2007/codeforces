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

lli i, cnt, j, x;
string s;

int main()
{
    cin >> s;
    for( i = s.size() - 1; i >= 0; i-- ){
        x = s[i] - '0';
        if( x % 4 == 0 )cnt++;
        if( i > 0 ){
            x = s[i - 1] - '0';
            x = x * 10 + s[i] - '0';
            if( x % 4 == 0 )cnt += i;
        }
    }
    cout << cnt << endl;
}
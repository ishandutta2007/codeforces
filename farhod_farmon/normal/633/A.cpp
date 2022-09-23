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

int a, b, c, i;
bool used[11111];

int main()
{
    cin >> a >> b >> c;
    used[0] = true;
    for( i = 0; i <= c; i++ ){
        if( !used[i] )continue;
        used[i + b] = used[i + a] = true;
    }
    if( used[c] )cout << "Yes" << endl;
    else cout << "No" << endl;
}
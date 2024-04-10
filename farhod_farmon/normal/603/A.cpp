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

string s;
int i, d[2], n;

int main()
{
    cin >> n >> s;
    for( i = 1; i <= n; i++ ){
        int x = s[i - 1] - '0';
        d[x] = d[x ^ 1] + 1;
    }
    cout << min(n, max(d[1], d[0]) + 2) << endl;
}
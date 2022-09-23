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

int n, p, b, a, i, j, h;

int main()
{
    cin >> n >> p >> b;
    h = n * b;
    while( n > 1 ){
        j = 2;
        while( j * 2 <= n )j *= 2;
        a += j * p + j / 2;
        n -= j / 2;
    }
    cout << a << " " << h << endl;
}
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

lli cnt, n, i, cnt1;

int main()
{
    cin >> n;
    cnt = n / 2 + n / 3 + n / 5 + n / 7;
    cnt -= n / 6 + n / 10 + n / 14 + n / 15 + n / 21 + n / 35;
    cnt += n / 30 + n / 42 + n / 70 + n / 105;
    cnt -= n / 210;
    cout << n - cnt << endl;
}
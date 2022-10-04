#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

bool inter(int a, int b, int c, int d) {
    a = max(a, c);
    b = min(b, d);
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;
    int h, m;
    char c;
    cin >> h >> c >> m;
    m = h * 60 + m;
    int ans = 0;
    int s = 5 * 60;
    int e = 24 * 60;
    for (int i = s; i < e; i += b) {
        if (inter(m, m + ta, i, i + tb)) ++ans;
    }
    cout << ans << '\n';
}
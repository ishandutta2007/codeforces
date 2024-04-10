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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int hh, mm, H, D, N;
    double C;
    cin >> hh >> mm >> H >> D >> C >> N;
    double ans = (H + N - 1) / N * C;
    int cur = max(0, 20 * 60 - (hh * 60 + mm));
    H += cur * D;
    C *= 0.8;
    ans = min(ans, int((H + N - 1) / N) * C);
    cout << fixed << setprecision(16) << ans << endl;
}
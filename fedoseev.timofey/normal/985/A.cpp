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
    int n;
    cin >> n;
    vector <int> a(n / 2);
    for (int i = 0; i < n / 2; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int ans1 = 0, ans2 = 0;
    int c1 = 1, c2 = 2;
    for (int i = 0; i < n / 2; ++i) {
        ans1 += abs(a[i] - c1);
        ans2 += abs(a[i] - c2);
        c1 += 2;
        c2 += 2;
    }
    cout << min(ans1, ans2) << '\n';
}
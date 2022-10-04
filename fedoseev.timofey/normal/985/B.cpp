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
    int n, m;
    cin >> n >> m;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> cnt(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '1') ++cnt[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        bool bad = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '1' && cnt[j] == 1) {
                bad = 1;
                break;
            }
        }
        if (!bad) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
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
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        --a[i];
    }
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        vector <int> c(m);
        for (int j = i; j < n; ++j) {
            ++c[a[j]];
            if (c == b) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}
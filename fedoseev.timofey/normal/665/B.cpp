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

vector <int> p;
int k;

int get(int x) {
    int res = 0;
    for (int i = 0; i < k; ++i) {
        if (p[i] == x) {
            res = i + 1;
            p.erase(p.begin() + i);
            p.insert(p.begin(), x);
            break;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m >> k;
    p.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            ans += get(x);
        }
    }
    cout << ans << '\n';
}
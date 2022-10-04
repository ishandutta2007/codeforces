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
    vector <bool> first(10);
    vector <int> sum(10);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        first[s[0] - 'a'] = 1;
        int now = 1;
        for (int j = 0; j < s.size(); ++j) {
            sum[s[s.size() - 1 - j] - 'a'] += now;
            now *= 10;
        }
    }
    bool done = 0;
    int ind = -1, can = -1;
    for (int i = 0; i < 10; ++i) {
        if (!first[i] && sum[i] > can) {
            can = sum[i];
            ind = i;
        }
    }
    done = 1;
    vector <bool> used(10);
    used[ind] = 1;
    ll ans = 0;
    for (int dg = 1; dg < 10; ++dg) {
        can = -1, ind = -1;
        for (int i = 0; i < 10; ++i) {
            if (!used[i] && sum[i] > can) {
                can = sum[i];
                ind = i;
            }
        }
        ans += (ll)dg * sum[ind];
        used[ind] = 1;
    }
    cout << ans << '\n';
}
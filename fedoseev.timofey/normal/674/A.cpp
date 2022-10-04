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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector <int> ans(n);
    for (int l = 0; l < n; ++l) {
        vector <int> cnt(n);
        int lead = 0;
        for (int r = l; r < n; ++r) {
            int cur = a[r];
            ++cnt[cur];
            if (cnt[cur] > cnt[lead] || ((cnt[cur] == cnt[lead]) && cur < lead)) {
                lead = cur;
            }
            ++ans[lead];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}
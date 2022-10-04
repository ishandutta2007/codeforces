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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> ans;
    vector <int> used(256);
    vector <int> sz(256);
    for (int i = 0; i < 256; ++i) used[i] = -1;
    for (int i = 0; i < n; ++i) {
        if (used[a[i]] != -1) {
            ans.push_back(used[a[i]]);
        }
        else {
            int best1 = 1e9;
            for (int j = max(0, a[i] - k + 1); j <= a[i]; ++j) {
                if (used[j] == -1) {
                    best1 = j;
                    break;
                }
            }
            int best2 = 1e9;
            for (int j = a[i]; j >= 0; --j) {
                if (used[j] != -1 && sz[j] + a[i] - j <= k) {
                    best2 = j;
                    break;
                }
            }
            if (best1 < best2) {
                ans.push_back(best1);
                for (int j = best1; j <= a[i]; ++j) {
                    used[j] = best1;
                    sz[j] = a[i] - best1 + 1;
                }
            }
            else {
                ans.push_back(used[best2]);
                int nsz = sz[best2] + a[i] - best2;
                for (int j = best2 + 1; j <= a[i]; ++j) {
                    used[j] = used[best2];
                }
                for (int j = 0; j < 256; ++j) {
                    if (used[j] == used[best2]) {
                        sz[j] = nsz;
                    }
                }
            }
        }
    }
    for (auto e : ans) {
        cout << e << ' ';
    }
}
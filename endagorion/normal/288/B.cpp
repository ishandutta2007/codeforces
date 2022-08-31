#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

bool check(int k, const vector<int> &p) {
    bool ok = true;
    vector<bool> vis(k);
    vis[0] = true;
    int c = 1;
    for (int i = 0; i < k && c < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (vis[p[j]] && !vis[j]) {
                vis[j] = true;
                ++c;
            }
        }
    }
    return c == k;
}

int rec(int x, int k, vector<int> &p) {
    if (x == k) {
        return check(k, p) ? 1 : 0;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        p[x] = i;
        ans += rec(x + 1, k, p);
    }
    return ans;
}

const long long P = 1000000000 + 7;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    //int N;
    //cin >> N;
    int N, K;
    cin >> N >> K;
    long long ans = 1;
    for (int i = 0; i < K - 1; ++i) {
        ans *= K; ans %= P;
    }
    for (int i = 0; i < N - K; ++i) {
        ans *= N - K; ans %= P;
    }
    cout << ans << '\n';
    return 0;
}
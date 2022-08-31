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
#include <sstream>
#include <algorithm>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

long long fb[40];
long long c[40];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < 30; ++j) {
            if (x & (1 << j)) {
                ++fb[j];
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        int x;
        scanf("%d", &x);
        ++c[x];
    }

    int ans = 0;
    for (int i = 0; i < 30; ++i) {
        ll left = c[i];
        for (int j = i; j < 30 && left > 0; ++j) {
            ll pl = min(left, fb[j] << (j - i));
            left -= pl;
            ans += pl;
            int K = 1 << (j - i);
            ll res = (K - pl % K) % K;
            fb[j] -= (pl + K - 1) / K;
            for (int k = i; k < j; ++k) {
                if (res & (1 << (k - i))) {
                    ++fb[k];
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
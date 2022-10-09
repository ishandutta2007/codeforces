#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

const int N = 1e7 + 228;
const long long inf = 1e13 + 228;
int del[N];
int A[N];

long long calc(long long val, long long c) {
    long long res = 0;
    long long tmp = c;
    while (tmp <= val) {
        res += val / tmp;
        if ((__int128_t) tmp * c > val)
            break;
        tmp *= c;
    }
    return res;
}

unordered_map<int, long long> cnt(N);

bool check(long long val) {
    for (auto i : cnt) {
        if (calc(val, i.first) < i.second) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < N; ++i) {
        if (!del[i]) {
            for (int j = i; j < N; j += i) {
                if (!del[j] || del[j] > i)
                    del[j] = i;
            }
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        A[a + 1]++;
    }

    int c = k;
    for (int i = 2; i < N; ++i) {
        c -= A[i];
        int v = i;
        while (v > 1) {
            cnt[del[v]] += c;
            v /= del[v];
        }
    }
    // cout << "Meow\n";

    long long l = 0, r = inf;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << r << '\n';
    assert(check(r));
}
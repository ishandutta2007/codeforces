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
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

long long GCD(long long a, long long b) {
    return b == 0 ? a : GCD(b, a % b);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    long long N, M;
    string s, t;
    cin >> N >> M >> s >> t;
    long long K = GCD(s.size(), t.size());
    long long ans = N * s.size();
    long long Q = N * K / t.size();
    for (int i = 0; i < K; ++i) {
        //vector<int> a(26), b(26);
        i64 a[26], b[26];
        for (int j = 0; j < 26; ++j) {
            a[j] = b[j] = 0;
        }
        for (int j = i; j < s.size(); j += K) {
            ++a[s[j] - 'a'];
        }
        for (int j = i; j < t.size(); j += K) {
            ++b[t[j] - 'a'];
        }
        for (int j = 0; j < 26; ++j) {
            ans -= a[j] * b[j] * Q;
        }
    }
    cout << ans << '\n';

	return 0;
}
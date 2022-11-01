#include <bits/stdc++.h>
#define FOR(i, n, m) for(long long i = (n); i < (long long)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr ld eps = 1e-6;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
    REP(i, v.size()) {
        if(i)
            os << " ";
        os << v[i];
    }
    return os;
}

constexpr int N = 20000000 + 1;
constexpr int sqrtN = 4473;
bool isprime[20000000 + 1];
void sieve_of_atkin() {
  int n;
  for (int z = 1; z <= 5; z += 4) {
    for (int y = z; y <= sqrtN; y += 6) {
      for (int x = 1; x <= sqrtN && (n = 4*x*x+y*y) <= N; ++x)
        isprime[n] = !isprime[n];
      for (int x = y+1; x <= sqrtN && (n = 3*x*x-y*y) <= N; x += 2)
        isprime[n] = !isprime[n];
    }
  }
  for (int z = 2; z <= 4; z += 2) {
    for (int y = z; y <= sqrtN; y += 6) {
      for (int x = 1; x <= sqrtN && (n = 3*x*x+y*y) <= N; x += 2)
        isprime[n] = !isprime[n];
      for (int x = y+1; x <= sqrtN && (n = 3*x*x-y*y) <= N; x += 2)
        isprime[n] = !isprime[n];
    }
  }
  for (int y = 3; y <= sqrtN; y += 6) {
    for (int z = 1; z <= 2; ++z) {
      for (int x = z; x <= sqrtN && (n = 4*x*x+y*y) <= N; x += 3)
        isprime[n] = !isprime[n];
    }
  }
  for (int n = 5; n <= sqrtN; ++n)
    if (isprime[n])
      for (int k = n*n; k <= N; k+=n*n)
        isprime[k] = false;
  isprime[2] = isprime[3] = true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> cnt(20000001, 0);
    vector<ll> dp(20000001, 0);

    sieve_of_atkin();

    vector<int> prims;
    for(int i = 2; i <= 20000000; i++) {
        if(isprime[i])
            prims.pb(i);
    }

    int n;
    cin >> n;

    vector<int> a(n);
    set<int> divs_set;
    vector<int> divs;
    REP(i, n) {
        cin >> a[i];
        for(int num = 1; num * num <= a[i]; num += 1) {
            if(a[i] % num != 0)
                continue;
            cnt[num] += 1;
            if(divs_set.count(num) == 0) {
                divs_set.insert(num);
                divs.pb(num);
            }
            if(num != a[i] / num) {
                cnt[a[i] / num] += 1;
                if(divs_set.count(a[i] / num) == 0) {
                    divs_set.insert(a[i] / num);
                    divs.pb(a[i] / num);
                }
            }
        }
    }

    for(ll i = 20000000; i >= 1; i -= 1) {
        if(cnt[i] == 0)
            continue;
        dp[i] = cnt[i] * i;
        for(auto p: prims) {
            if(i * p > 20000000)
                break;
            dp[i] = max(dp[i], dp[i * p] + (cnt[i] - cnt[i * p]) * i);
        }
    }

    cout << dp[1] << endl;
    return 0;
}
//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  const int N = (1<<20) + 1;
  vector<bool> have(N);

  int T;
  cin >> T;
  while(T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), [](char c) {
      return c == '0' ? '1' : '0';
    });
    const int m = 20;
    int len = min(m, k);

    int cnt = 0;
    vector<int> memo;
    for(int i=0; i+len<=n; i++) {
      if(cnt >= k - len) {
        memo.push_back(stoi(s.substr(i, len), 0, 2));
        have[memo.back()] = true;
      }
      if(s[i] == '0') {
        cnt++;
      } else {
        cnt = 0;
      }
    }

    for(int bm=0; bm<=1<<len; bm++) {
      if(have[bm]) continue;
      if(bm < 1<<len) {
        cout << "YES" << nl;
        cout << string(k-len, '0');
        for(int i=0; i<len; i++) {
          cout << (bm >> (len-1-i) & 1);
        }
        cout << nl;
      } else {
        cout << "NO" << nl;
      }
      break;
    }

    for(int it : memo) {
      have[it] = false;
    }
  }

  return 0;
}
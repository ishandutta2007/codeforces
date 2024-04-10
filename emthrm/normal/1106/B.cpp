#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<tuple<long long, int, long long>> cia(n);
  vector<int> a(n), c(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> c[i];
  REP(i, n) cia[i] = make_tuple(c[i], i, a[i]);
  sort(ALL(cia));
  // REP(i, n) cout << get<0>(cia[i]) << ' '<<get<1>(cia[i])<< ' ' <<get<2>(cia[i]) << '\n';
  // return 0;
  map<int, int> mp;
  REP(i, n) mp[get<1>(cia[i])] = i;
  int now = 0;
  REP(repeat, m) {
    int t, d; cin >> t >> d;
    --t;
    long long ans = 0;
    int idx = mp[t];
    if (get<2>(cia[idx]) >= d) {
      ans += d * get<0>(cia[idx]);
      get<2>(cia[idx]) -= d;
    } else {
      ans += get<2>(cia[idx]) * get<0>(cia[idx]);
      d -= get<2>(cia[idx]);
      get<2>(cia[idx]) = 0;
      for (; now < n; ++now) {
        if (get<2>(cia[now]) >= d) {
          ans += d * get<0>(cia[now]);
          get<2>(cia[now]) -= d;
          d = 0;
          break;
        } else {
          ans += get<2>(cia[now]) * get<0>(cia[now]);
          d -= get<2>(cia[now]);
          get<2>(cia[now]) = 0;
        }
      }
      if (d > 0) ans = 0;
    }
    cout << ans << '\n';
  }
  return 0;
}
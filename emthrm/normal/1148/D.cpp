#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
using P = pair<int, int>;

vector<int> ans;
void solve(const vector<pair<P, int> > &ab) {
  for (int i = ab.size() - 1; i >= 0; --i) ans.emplace_back(ab[i].second + 1);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<pair<P, int> > nobori, kudari;
  REP(i, n) {
    int a, b; cin >> a >> b;
    if (a < b) nobori.emplace_back(make_pair(make_pair(a, b), i));
    else kudari.emplace_back(make_pair(make_pair(b, a), i));
  }
  if (nobori.size() >= kudari.size()) {
    sort(ALL(nobori));
    solve(nobori);
  } else {
    sort(ALL(kudari));
    solve(kudari);
    reverse(ALL(ans));
  }
  cout << ans.size() << '\n';
  REP(i, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  return 0;
}
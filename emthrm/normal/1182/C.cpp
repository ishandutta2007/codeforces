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
struct L {
  string a, b, c, d;
};

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  map<int, vector<string> > mp;
  map<char, bool> vowel;
  vowel['a'] = true; vowel['i'] = true; vowel['u'] = true; vowel['e'] = true; vowel['o'] = true;
  while (n--) {
    string s; cin >> s;
    int cnt = 0;
    for (char c : s) cnt += vowel[c];
    mp[cnt].emplace_back(s);
  }
  vector<pair<string, string> > last, pr;
  for (auto e : mp) {
    vector<vector<string> > saigo(26);
    for (string s : e.second) {
      int len = s.length();
      for (int i = len - 1; i >= 0; --i) {
        if (vowel[s[i]]) {
          saigo[s[i] - 'a'].emplace_back(s);
          break;
        }
      }
    }
    vector<string> amari;
    REP(i, 26) {
      int sz = saigo[i].size();
      if (sz & 1) {
        amari.emplace_back(saigo[i].back());
        --sz;
      }
      for (int j = 0; j < sz; j += 2) {
        pr.emplace_back(saigo[i][j], saigo[i][j + 1]);
      }
    }
    int sz = amari.size();
    if (sz & 1) --sz;
    for (int i = 0; i < sz; i += 2) {
      last.emplace_back(amari[i], amari[i + 1]);
    }
  }
  vector<L> ans;
  if (pr.size() > last.size()) {
    int sz = last.size();
    REP(i, sz) {
      L l;
      l.a = last[i].first;
      l.b = pr[i].first;
      l.c = last[i].second;
      l.d = pr[i].second;
      ans.emplace_back(l);
    }
    int sz2 = pr.size();
    if ((sz2 - sz) & 1) --sz2;
    for (int i = sz; i < sz2; i += 2) {
      L l;
      l.a = pr[i].first;
      l.b = pr[i + 1].first;
      l.c = pr[i].second;
      l.d = pr[i + 1].second;
      ans.emplace_back(l);
    }
  } else {
    int sz = pr.size();
    REP(i, sz) {
      L l;
      l.a = last[i].first;
      l.b = pr[i].first;
      l.c = last[i].second;
      l.d = pr[i].second;
      ans.emplace_back(l);
    }
  }
  cout << ans.size() << '\n';
  for (L l : ans) cout << l.a << ' ' << l.b << '\n' << l.c << ' ' << l.d << '\n';
  return 0;
}
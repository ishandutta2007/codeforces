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
const int CHARACTER = 26;
vector<vector<int> > nx_init(const string &str) {
  int n = str.size();
  vector<vector<int> > nx(n, vector<int>(CHARACTER, n));
  nx[n - 1][str[n - 1] - 'a'] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    REP(j, CHARACTER) nx[i][j] = nx[i + 1][j];
    nx[i][str[i] - 'a'] = i;
  }
  return nx;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string s; cin >> s;
  vector<vector<int> > nx = nx_init(s);
  int m; cin >> m;
  while (m--) {
    string t; cin >> t;
    vector<int> cnt(26, 0);
    for (char c : t) ++cnt[c - 'a'];
    set<int> st;
    REP(i, 26) if (cnt[i] > 0) st.emplace(i);
    int pos = -1;
    while (!st.empty()) {
      int letter, idx = INF;
      for (int c : st) if (nx[pos + 1][c] < idx) {
        letter = c;
        idx = nx[pos + 1][c];
      }
      --cnt[letter];
      if (cnt[letter] == 0) st.erase(letter);
      pos = idx;
    }
    cout << pos + 1 << '\n';
  }
  return 0;
}
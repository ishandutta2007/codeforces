#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i =(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
};

vector<pair<char, int> > rle(const string &s) {
  int n = s.size();
  vector<pair<char, int> > res;
  char now = s[0];
  int cnt = 1;
  FOR(i, 1, n) {
    if (s[i] != now) {
      res.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  res.emplace_back(now, cnt);
  return res;
}

int main() {
  string s; cin >> s;
  auto p = rle(s);
  if (p.size() % 2 == 0 || p[p.size() / 2].second < 2) {
    cout << 0 << '\n';
    return 0;
  }
  REP(i, p.size() / 2) {
    if (p[i].first != p[p.size() - 1 - i].first || p[i].second + p[p.size() - 1 - i].second < 3) {
      cout << 0 << '\n';
      return 0;
    }
  }
  cout << p[p.size() / 2].second + 1 << '\n';
  return 0;
}
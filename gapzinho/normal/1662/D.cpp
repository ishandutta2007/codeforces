#include <bits/stdc++.h>
using namespace std;


#define int long long
#define endl "\n"

const int ms = 210;

string u, v;
int n, m;

int dp[ms][ms];
int dp1[ms][ms];
set<string> st;
set<string> st4;
vector<int> v1[ms], v2[ms];

bool get(int x, int y, string &s) {
  if(x == y) return 1;
  int &ans = dp1[x][y];
  if(ans != -1) return ans;
  ans = 0;
  if(y-x < 2) return ans;
  for(int i = 0; i <= 2; i++) {
    int j = 2-i;
    string k = (i ? s.substr(x, i) : "") + (j ? s.substr(y-j, j) : "");
    ans = ans || (st.count(k) && get(x+i, y-j, s));
  }
  if(y-x < 4) return ans;
  for(int i = 0; i <= 4; i++) {
    int j = 4-i;
    string k = (i ? s.substr(x, i) : "") + (j ? s.substr(y-j, j) : "");
    ans = ans || (st4.count(k) && get(x+i, y-j, s));
  }
  return ans;
}

bool solve(int x, int y) {
  if(x >= n && y >= m) {
    return 1;
  }
  int &cur = dp[x][y];
  if(cur != -1) return cur;
  cur = 0;
  if(x < n && y < m && u[x] == v[y]) {
    cur = solve(x + 1, y + 1);
  }
  if(x < n) {
    for(int k : v1[x]) cur = cur || solve(k, y);
  }
  if(y < m) {
    for(int k : v2[y]) cur = cur || solve(x, k);
  }
  return cur;
}

string get(string &s) {
  string ans = "";
  for(char c : s) {
    if(c == 'B') continue;
    if(!ans.empty() && (*ans.rbegin()) == c) {
      ans.pop_back();
    } else {
      ans.push_back(c);
    }
  }
  return ans;
}

void solve() {
  cin >> u >> v;
  vector<int> x(500), y(500);
  for(char c : u) {
    x[c-'A']++;
  }
  for(char c : v) {
    y[c-'A']++;
  }
  int n = u.size(), m = v.size();
  if(x[1] % 2!= y[1] % 2) {
    cout << "NO\n";
    return;
  }
  string p = get(u);
  string f = get(v);
  if(p == f) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  // memset(dp, -1, sizeof dp);
  // n = u.size();
  // m = v.size();
  // memset(dp1, -1, sizeof dp1);
  // for(int i = 0; i <= n; i++) {
  //   v1[i].clear();
  // }
  // for(int i = 0; i <= m; i++) {
  //   v2[i].clear();
  // }
  // for(int i = 0; i < n; i++) {
  //   for(int j = i+1; j <= n; j++) {
  //     if(get(i, j, u)) {
  //       // cout << i << " - "  << j << endl;
  //       v1[i].emplace_back(j);
  //     }
  //   }
  // }
  // memset(dp1, -1, sizeof dp1);
  // for(int i = 0; i < m; i++) {
  //   for(int j = i+1; j <= m; j++) {
  //     if(get(i, j, v)) v2[i].emplace_back(j);
  //   }
  // }
  // if(solve(0, 0)) {
  //   cout << "YES" << endl;
  // } else cout << "NO" << endl;
}

 main() {
   ios::sync_with_stdio(0); cin.tie(0);
   st.emplace("AA");
   st.emplace("BB");
   st.emplace("CC");
   st4.emplace("ABAB");
   st4.emplace("BCBC");
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
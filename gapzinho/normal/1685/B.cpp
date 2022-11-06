#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 1e6+5;

int v[ms];

void solve() {
  int a, b, ab, ba;
  cin >> a >> b >> ab >> ba;
  string S;
  cin >> S;
  int n = S.size();
  int cntA = 0, cntB = 0;
  for(int i = 0; i < n; i++) {
    cntA += S[i] == 'A';
    cntB += S[i] == 'B';
  }
  if(cntA != a + ab + ba || cntB != b + ab + ba) {
    cout << "NO" << '\n';
    return;
  }
  // cout << ab << " " << ba << " " << s << endl;
  vector<string> sections;
  string curSec;
  curSec.push_back(S[0]);
  for(int i = 1; i < n; i++) {
    if(S[i] != S[i-1]) {
      curSec.push_back(S[i]);
    } else {
      sections.push_back(curSec);
      curSec.clear();
      curSec.push_back(S[i]);
    }
  }
  sections.push_back(curSec);
  int tantoFaz = 0;
  vector<int> goodA;
  vector<int> goodB;
  for(auto &s : sections) { 
    // cout << s << endl;
    if(s.size() % 2 == 0) {
      if(s[0] == 'A') goodA.emplace_back(s.size() / 2);
      else goodB.emplace_back(s.size() / 2);
    } else {
      tantoFaz += (s.size() / 2);
    }
  }
  sort(goodA.begin(), goodA.end());
  sort(goodB.begin(), goodB.end());
  for(int k : goodA) {
    if(k <= ab) {
      ab -= k;
    } else {
      tantoFaz += k-1;
    }
  }
  for(int k : goodB) {
    if(k <= ba) {
      ba -= k;
    } else {
      tantoFaz += k-1;
    }
  }
  // cout << ab << " " << ba << " " << tantoFaz << endl;
  if(ab + ba <= tantoFaz) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}
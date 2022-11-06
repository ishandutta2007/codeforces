#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int ms = 500;

int cnt1[ms], cnt2[ms], cnt3[ms];

int get(int cnt[]) {
  string s;
  cin >> s;
  for(char c : s) {
    cnt[c-'A']++;
  }
  return s.size();
}

void add(queue<int> &v, int cnt, int k) {
  for(int i = 0; i < cnt; i++) {
    v.emplace(k);
  }
}

void solve() {
  get(cnt1);
  get(cnt2); get(cnt3);
  queue<int> a, b, c, ab, bc, ca;
  vector<ii> ans;
  for(int i = 0; i < 26; i++) {
    int x = 0;
    while(cnt1[i] && cnt2[i] && cnt3[i]) {
      if(cnt1[i] > cnt2[i] && cnt1[i] > cnt3[i]) {
        ab.emplace(i);
        ca.emplace(i);
        cnt1[i]--;
      } else if(cnt2[i] > cnt1[i] && cnt2[i] > cnt3[i]) {
        ab.emplace(i);
        bc.emplace(i);
        cnt2[i]--;
      } else if(cnt3[i] > cnt2[i] && cnt3[i] > cnt1[i]) {
        ca.emplace(i);
        bc.emplace(i);
        cnt3[i]--;
      } else {
        x++;
      }
      cnt1[i]--; cnt2[i]--; cnt3[i]--;
    }
    while(x > 1) {
      x -= 2;
      ab.emplace(i);
      bc.emplace(i);
      ca.emplace(i);
    }
    if(x) {
      ans.emplace_back(i, i);
    }
    while(cnt1[i] && cnt2[i]) {
      ab.emplace(i);
      cnt1[i]--; cnt2[i]--;
    }
    while(cnt3[i] && cnt2[i]) {
      bc.emplace(i);
      cnt3[i]--; cnt2[i]--;
    }
    while(cnt1[i] && cnt3[i]) {
      ca.emplace(i);
      cnt1[i]--; cnt3[i]--;
    }
    while(cnt1[i]) {
      cnt1[i]--;
      a.emplace(i);
    }
    while(cnt2[i]) {
      cnt2[i]--;
      b.emplace(i);
    }
    while(cnt3[i]) {
      cnt3[i]--;
      c.emplace(i);
    }
  }
  while(!ab.empty() && !c.empty()) {
    ans.emplace_back(ab.front(), c.front());
    ab.pop(); c.pop();
  }
  while(!bc.empty() && !a.empty()) {
    ans.emplace_back(bc.front(), a.front());
    bc.pop(); a.pop();
  }
  while(!ca.empty() && !b.empty()) {
    ans.emplace_back(ca.front(), b.front());
    ca.pop(); b.pop();
  }
  while(!ab.empty() && !bc.empty() && !ca.empty()) {
    ans.emplace_back(ab.front(), bc.front());
    ans.emplace_back(ab.front(), ca.front());
    ab.pop(); bc.pop(); ca.pop();
  }
  while(!ab.empty()) {
    ans.emplace_back(ab.front(), ab.front());
    ab.pop();
  }
  while(!bc.empty()) {
    ans.emplace_back(bc.front(), bc.front());
    bc.pop();
  }
  while(!ca.empty()) {
    ans.emplace_back(ca.front(), ca.front());
    ca.pop();
  }
  while(!a.empty() || !b.empty() || !c.empty()) {
    if(b.empty() && c.empty()) {
      ans.emplace_back(a.front(), a.front());
      a.pop();
    } else if(a.empty() && c.empty()) {
      ans.emplace_back(b.front(), b.front());
      b.pop();
    } else if(a.empty() && b.empty()) {
      ans.emplace_back(c.front(), c.front());
      c.pop();
    } else if(a.size() >= c.size() && b.size() >= c.size()) {
      ans.emplace_back(a.front(), b.front());
      a.pop(); b.pop();
    }else if(a.size() >= b.size() && c.size() >= b.size()) {
      ans.emplace_back(a.front(), c.front());
      a.pop(); c.pop();
    }else if(c.size() >= a.size() && b.size() >= a.size()) {
      ans.emplace_back(c.front(), b.front());
      c.pop(); b.pop();
    } else {
      assert(false);
    }
  }
  cout << ans.size() << '\n';
  for(auto [x, y] : ans) {
    cout << (char) ('A' + x) << (char) ('A' + y) << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}
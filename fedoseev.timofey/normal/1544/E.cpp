#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

template <typename T>
int kmp(const T &s) {
  int n = s.size();
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(s[i] == s[k])) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  int mx = 0;
  for (int i = 0; i < n; ++i) mx = max(mx, p[i]);
  return mx;
}

string smart(string s) {
  int n = s.size();
  sort(s.begin(), s.end());
  if (s[0] == s[n - 1]) {
    return s;
  }
  const int K = 26;
  vector <int> cnt(K);
  for (auto c : s) {
    ++cnt[c - 'a'];
  }
  int cnt_let = 0;
  for (int i = 0; i < K; ++i) {
    if (cnt[i] > 0) {
      ++cnt_let;
    }
  }
  int mn = -1;
  for (int i = 0; i < K; ++i) {
    if (cnt[i] == 1) {
      mn = i;
      break;
    }
  }
  string ans;
  if (mn != -1) {
    ans = char('a' + mn);
    cnt[mn] = 0;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        ans += char('a' + i);
      }
    }
  } else {
    for (int i = 0; i < K; ++i) {
      if (cnt[i] != 0) {
        mn = i;
        break;
      }
    }
    string other;
    for (int i = mn + 1; i < K; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        other += char('a' + i);
      }
    }
    reverse(other.begin(), other.end());
    int have = cnt[mn];
    if (have - 2 <= (int)other.size()) {
      ans += char('a' + mn);
      --have;
      int it = 0;
      while (have > 0 || !other.empty()) {
        if (it == 1 || have == 0) {
          ans.push_back(other.back());
          other.pop_back();
        } else {
          ans += char('a' + mn);
          --have;
        }
        it ^= 1;
      }
    } else if (cnt_let >= 3) {
      ans += char('a' + mn);
      --have;
      char bad = other.back();
      ans += other.back();
      other.pop_back();
      while (have > 0) {
        ans += char('a' + mn);
        --have;
      }
      for (int i = (int)other.size() - 1; i >= 0; --i) {
        if (other[i] != bad) {
          ans += other[i];
          other.erase(other.begin() + i);
          break;
        }
      }
      while (!other.empty()) {
        ans += other.back();
        other.pop_back();
      }
    } else {
      ans += char('a' + mn);
      --have;
      while (!other.empty()) {
        ans += other.back();
        other.pop_back();
      }
      while (have > 0) {
        ans += char('a' + mn);
        --have;
      }
    }
  }
  return ans;
} 

string stupid(string s) {
  sort(s.begin(), s.end());
  string ans = s;
  int res = kmp(ans);
  do {
    int cur = kmp(s);
    if (cur < res || (cur == res && s < ans)) {
      ans = s;
      res = cur;
    }
  } while (next_permutation(s.begin(), s.end()));
  return ans;
}

void stress() {
  mt19937 rnd(124);
  for (int tt = 0; tt < 100000; ++tt) {
    int cnt = rnd() % 5 + 1;
    int n = rnd() % 9 + 1;
    string s;
    for (int i = 0; i < n; ++i) {
      int x = rnd() % cnt;
      s += char('a' + x);
    }
    string sm = smart(s);
    string st = stupid(s);
    if (sm != st) {
      cout << s << endl;
      exit(0);
    }
    if (tt % 1000 == 0) {
      cout << tt << endl;
    }
  }
  exit(0);
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  //stress();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << smart(s) << '\n';
  }
}
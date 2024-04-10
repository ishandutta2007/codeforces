#include <bits/stdc++.h>

using namespace std;


int n;
string s;
vector<int> v;

void solve(int l, int r) {
  if (l > r) {
    return;
  }
  if (r - l + 1 <= 3) {
    cout << s[l];
    return;
  }
  vector<int> cnt(3, 0);
  cnt[v[l]]++;
  cnt[v[l + 1]]++;
  cnt[v[r]]++;
  cnt[v[r - 1]]++;
  for (int i = 0; i < 3; i++) {
    if (cnt[i] >= 2) {
      cout << (char) ('a' + i);
      solve(l + 2, r - 2);
      cout << (char) ('a' + i);
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> s;
  n = s.size();
  v.resize(n);
  for (int i = 0; i < n; i++) {
    v[i] = s[i] - 'a';
  }
  solve(0, n - 1);


  return 0;
}
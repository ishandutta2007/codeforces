#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';
using ll = long long;
int T = -1;

int main() {
  if(T < 0) { cin.tie(0)->sync_with_stdio(0); cin >> T; }
  if(--T) main();

  string s;
  cin >> s;
  int n = size(s);
  vector<bitset<26>> have(n+1);
  for(int i=n-1; i>=0; i--) {
    have[i] = have[i+1];
    have[i].set(s[i] - 'a');
  }

  string ans;
  bitset<26> done;
  for(int t=have[0].count(), lb=0; t>0; t--) {
    char c = 0;
    for(int i=lb; i<n && have[i].count() == t; i++) {
      if(!done[s[i] - 'a']) {
        c = max(c, s[i]);
      }
    }
    lb = s.find(c, lb) + 1;
    for(int i=0; i<n; i++) {
      have[i].reset(c - 'a');
    }
    done.set(c - 'a');
    ans.push_back(c);
  }
  cout << ans << nl;

  return 0;
}
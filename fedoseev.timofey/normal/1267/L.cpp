#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, l, k;
  cin >> n >> l >> k;
  string s;
  cin >> s;
  vector <int> cnt(26);
  for (char c : s) ++cnt[c - 'a'];
  string ans;
  int have = k - 1;
  for (int i = 0; i < l; ++i) {
    int sum = 0;
    for (char c = 0; c < 26; ++c) {
      if (cnt[c] == 0) continue;
      if (sum + cnt[c] - 1 >= have) {
        --cnt[c];
        int cur = have;
        for (int t = 0; t < 26; ++t) {
          int r = min(cur, cnt[t]);
          cnt[t] -= r;
          cur -= r;
        }
        have -= sum;
        ans.push_back(char('a' + c));
        break;
      }
      sum += cnt[c];
    }
  }
  vector <string> rs(n);
  for (int i = 0; i < n; ++i) rs[i].resize(l, '#');
  rs[k - 1] = ans;
  for (int i = 0; i < 26; ++i) cnt[i] = 0;
  for (char c : s) ++cnt[c - 'a'];
  set <int> who;
  for (int i = 0; i + 1 < k; ++i) who.insert(i);
  int uk = 0;
  for (int i = 0; i < l; ++i) {
    --cnt[ans[i] - 'a'];
    set <int> nwho;
    for (int j = 0; j <= ans[i] - 'a'; ++j) {
      while (!who.empty() && cnt[j] > 0) {
        int id = *who.begin();
        who.erase(who.begin());
        rs[id][i] = char('a' + j);
        if (j == ans[i] - 'a') nwho.insert(id);
        --cnt[j];
      }
    }
    who = nwho;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      if (rs[i][j] == '#') {
        for (int t = 0; t < 26; ++t) {
          if (cnt[t] > 0) {
            --cnt[t];
            rs[i][j] = char('a' + t);
            break;
          }
        }
      }
    }
  }
  sort(rs.begin(), rs.end());
  for (string s : rs) cout << s << '\n';
}
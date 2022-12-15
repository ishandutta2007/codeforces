#include<bits/stdc++.h>
using namespace std;

const int ms = 2e5+5, sigma = 26;

int len[ms*2], link[ms*2], nxt[ms*2][sigma], cnt[ms*2];
int sz, last;
pair<int, int> st[2*ms];

void build(string &s, string &t) {
  len[0] = 0; link[0] = -1;
  sz = 1; last = 0;
  memset(nxt[0], -1, sizeof nxt[0]);
  for(int i = 0; i < s.size(); i++) {
    int c = s[i]-'a', cur = sz++;
    len[cur] = len[last]+1;
    if(t[i] == '0') cnt[cur] = 1;
    memset(nxt[cur], -1, sizeof nxt[cur]);
    int p = last;
    while(p != -1 && nxt[p][c] == -1) {
      nxt[p][c] = cur; p = link[p];
    }
    if(p == -1) {
      link[cur] = 0;
    } else {
      int q = nxt[p][c];
      if(len[p] + 1 == len[q]) {
        link[cur] = q;
      } else {
        len[sz] = len[p]+1; link[sz] = link[q];
        memcpy(nxt[sz], nxt[q], sizeof nxt[q]);
        while (p != -1 && nxt[p][c] == q) {
          nxt[p][c] = sz; p = link[p];
        }
        link[q] = link[cur] = sz++;
      }
    }
    last = cur;
  }
}

int dp[2*ms];

int solve(int p) {
  if(~dp[p]) return dp[p];
  dp[p] = 1;
  for(int i = 0; i < 26; i++) {
    if(~nxt[p][i]) {
      dp[p] += solve(nxt[p][i]);
    }
  }
  return dp[p];
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  string s, t;
  cin >> n >> s >> t;
  build(s, t);
  for(int i = 0; i < sz; i++) {
    st[i] = {len[i], i};
  }
  sort(st, st+sz);
  for(int i = sz-1; i>= 0; i--) {
    cnt[link[st[i].second]] += cnt[st[i].second];
  }
  long long ans = 0;
  for(int i = 0; i < sz; i++) {
    ans = max(ans, 1ll * cnt[i] * len[i]);
  }
  cout << ans << '\n';
}
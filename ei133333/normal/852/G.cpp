#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;

int N, M;
char s[55];
map< unsigned, int > st[55];
set< unsigned > used[55];

int dfs(const string &s, int idx, int sz, unsigned val)
{
  if(idx == s.size()) {
    if(st[sz].count(val)) {
      if(used[sz].count(val)) return (0);
      used[sz].emplace(val);
      return (st[sz][val]);
    } else {
      return (0);
    }
  } else if(s[idx] == '?') {
    int ret = dfs(s, idx + 1, sz, val);
    for(int j = 0; j < 5; j++) ret += dfs(s, idx + 1, sz + 1, (val + j) * mod);
    return (ret);
  } else {
    int p = s[idx] - 'a';
    return (dfs(s, idx + 1, sz + 1, (val + p) * mod));
  }
}

int main()
{

  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%s", s);
    string p(s);
    unsigned val = 0;
    for(int j = 0; j < p.size(); j++) p[j] -= 'a';
    for(int j = 0; j < p.size(); j++) val = (val + p[j]) * mod;
    ++st[p.size()][val];
  }

  for(int i = 0; i < M; i++) {
    scanf("%s", s);
    string p(s);
    for(int j = 0; j < 55; j++) used[j].clear();
    printf("%d\n", dfs(p, 0, 0, 0));
  }
}
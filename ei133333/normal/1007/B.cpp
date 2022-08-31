#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {

  int T;
  scanf("%d", &T);

  int conv[100001];
  vector< int > pop[4];
  for(int i = 0; i < (1 << 3); i++) {
    pop[__builtin_popcount(i)].emplace_back(i);
  }
  int need[1 << 3][1 << 3] = {{}};
  for(int i = 0; i < (1 << 3); i++) {
    for(int j = 0; j < (1 << 3); j++) {
      for(int k = 0; k < 3; k++) {
        for(int l = 0; l < 3; l++) {
          if(k == l) continue;
          if((i >> k) & 1 && (j >> l) & 1) {
            int other = -1;
            for(int m = 0; m < 3; m++) {
              if(k == m || l == m) continue;
              other = m;
            }
            need[i][j] |= 1 << other;
          }
        }
      }
    }
  }
  int lim = (1 << 3) - 1;

  vector< int > look[1 << 3];
  for(int i = 0; i < 1 << 3; i++) {
    for(auto &p : pop[2]) {
      if((p | i) == lim) look[i].emplace_back(p);
    }
    for(auto &p : pop[3]) {
      if((p | i) == lim) look[i].emplace_back(p);
    }
  }

  int q = 1;

  vector< int > stock[100001];
  for(int i = 1; i <= 100000; i++) {
    for(int j = 1; j * j <= i; j++) {
      if(i % j == 0) {
        stock[i].emplace_back(j);
        if(j * j != i) stock[i].emplace_back(i / j);
      }
    }
    sort(begin(stock[i]), end(stock[i]));
  }
  map< tuple< int, int, int >, int64 > memo;


  while(T--) {
    int S[3];
    for(int i = 0; i < 3; i++) {
      scanf("%d", &S[i]);
    }
    sort(S, S + 3);
    if(memo.count(make_tuple(S[0], S[1], S[2]))) {
      printf("%lld\n", memo[make_tuple(S[0], S[1], S[2])]);
      continue;
    }
    vector< int > ev;
    for(int i = 0; i < 3; i++) {
      for(auto &p : stock[S[i]]) ev.emplace_back(p);
    }
    sort(begin(ev), end(ev));
    ev.erase(unique(begin(ev), end(ev)), end(ev));
    for(int i = 0; i < ev.size(); i++) conv[ev[i]] = i;
    vector< int > to(ev.size());
    for(int i = 0; i < 3; i++) {
      for(auto &p : stock[S[i]]) to[conv[p]] |= 1 << i;
    }
    int64 ret = 0;
    for(auto &p : to) if(p == lim) ++ret;
    int64 mask[1 << 3] = {};
    for(auto &p : to) {
      for(auto &q : look[p]) ret += mask[q];
      mask[p]++;
    }
    memset(mask, 0, sizeof(mask));
    reverse(begin(to), end(to));
    for(auto &p : to) {
      for(auto &q : look[p]) ret += mask[q];
      mask[p]++;
    }
    reverse(begin(to), end(to));
    memset(mask, 0, sizeof(mask));
    mask[to[0]]++;
    int64 bitneed[1 << 3] = {};
    int64 all = 0;
    for(int i = 1; i < to.size(); i++) {
      if(to[i] == lim) {
        ret += all;
      } else {
        for(int j = 0; j < (1 << 3); j++) {
          if(j & to[i]) ret += bitneed[j];
        }
      }
      for(int j = 0; j < (1 << 3); j++) {
        if(need[j][to[i]]) all += mask[j];
        bitneed[need[j][to[i]]] += mask[j];
      }
      mask[to[i]]++;
    }
    printf("%lld\n", ret);
    memo[make_tuple(S[0], S[1], S[2])] = ret;
  }

}
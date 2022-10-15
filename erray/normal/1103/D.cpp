// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }

  long long g = 0;
  for (auto e : A) {
    g = gcd(e, g);
  }

  vector<long long> p;
  for (long long i = 2; i * i <= g; ++i) {
    int c = 0;
    while (g % i == 0) {
      g /= i;
      c += 1;
    }
    if (c > 0) {
      p.push_back(i);
    }
  }

  if (g != 1) {
    p.push_back(g);
  }
  debug(p);
  int sz = int(p.size());
  vector<vector<int>> a(N, vector<int>(sz));
  vector<long long> val(N, 1);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < sz; ++j) {
      while (A[i] % p[j] == 0) {
        a[i][j] += 1;
        val[i] *= p[j];
        A[i] /= p[j];
      }
    }
  }

  debug(a);
  debug(val);

  int k = int(p.size());
  assert(k <= 11);
  vector<long long> uni = val;
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  int size = int(uni.size());
  vector<vector<int>> vals(size);
  vector<vector<int>> ct(size);
  for (int i = 0; i < N; ++i) {
    int id = int(lower_bound(uni.begin(), uni.end(), val[i]) - uni.begin());
    vals[id].push_back(C[i]);
    ct[id] = a[i];
  }

  const int M = (1 << k);
  vector<vector<int>> match(M);
  for (int i = 0; i < M; ++i) {
    for (int j = 1; j < M; ++j) {
      if ((i & j) == 0) {
        match[i].push_back(j);
      }
    }
  }
  vector<vector<pair<long long, int>>> first(size, vector<pair<long long, int>>(M, {0, k + 5}));
  for (int c = 0; c < size; ++c) {
    vector<long long> mult(k, 1);
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < ct[c][i]; ++j) {
        mult[i] *= p[i];
      }
    }

    vector<long long> cost(M, 1);
    for (int i = 1; i < M; ++i) {
      int b = __lg(i);
      cost[i] = cost[i ^ (1 << b)] * mult[b];
    }

    for (int i = M - 1; i >= 0; --i) {
      for (int j = 0; j < k; ++j) {
        cost[i] = min(cost[i], cost[i | (1 << j)]);
      }
    }

    vector<bool> act(M);
    for (int i = 0; i < M; ++i) {
      act[i] = (cost[i] <= K);
    }
  
    vector<int> phase(M, 500);
    sort(vals[c].begin(), vals[c].end());
    int nm = int(vals[c].size());
    vector<long long> pref(nm + 1);
    for (int i = 0; i < nm; ++i) {
      pref[i + 1] = pref[i] + vals[c][i];
    }
    debug(c, ct[c], act, vals[c]);


    queue<int> que;
    que.push(0);
    phase[0] = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      debug(v, phase[v]);
      if (phase[v] <= nm) {
        first[c][v] = pair{pref[phase[v]], phase[v]};
      }
      for (auto o : match[v]) {
        int next = v | o;
        if (act[o] && phase[next] == 500) {
           phase[next] = phase[v] + 1;
           que.push(next);
        }
      }
    }
    //debug(c, first[c]);
  }

  //debug(first);
  
  const long long inf = (long long) 1e17;
  vector<vector<long long>> dp(M, vector<long long>(k + 1, inf));
  dp[0][0] = 0;
  for (int i = 0; i < size; ++i) {
    vector<vector<long long>> new_dp = dp;
    for (int c = 0; c < k; ++c) {
      for (int mask = 0; mask < M; ++mask) {
        for (auto o : match[mask]) {
          //debug(i, c, mask, o, first[i][o]);
          int go = c + first[i][o].second;
          if (go <= k) {
             new_dp[mask | o][go] = min(new_dp[mask | o][go], dp[mask][c] + first[i][o].first); 
          } 
        }
      }
    }
    swap(dp, new_dp);
  }

  long long ans = inf;
  for (int i = 0; i <= k; ++i) {
    debug(dp[M - 1][i]);
    if (dp[M - 1][i] != inf) {
      ans = min(ans, dp[M - 1][i] * i); 
    }  
  }
  cout << (ans == inf ? -1 : ans) << '\n';
}
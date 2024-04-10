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
typedef unsigned long long ul;

const int K = 15;

int sr[1 << K];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  for (int mask = 0; mask < (1 << K); ++mask) {
    vector <int> ord;
    for (int i = 0; i < K; ++i) {
      ord.push_back((mask >> i) & 1);
    }
    sort(ord.begin(), ord.end());
    int nmask = 0;
    for (int i = 0; i < (int)ord.size(); ++i) {
      nmask |= (ord[i] << (K - i - 1));
    }
    sr[mask] = nmask;
  }
  int n, q;
  cin >> n >> q;
  vector <ul> can;
  can.push_back(0);
  vector <int> used(n);
  for (int i = 0; i < q; ++i) {
    int k;
    cin >> k;
    vector <int> pos(k);
    vector <int> nw;
    for (int j = 0; j < k; ++j) {
      cin >> pos[j];
      --pos[j];
      if (!used[pos[j]]) {
        nw.push_back(pos[j]);
        used[pos[j]] = 1;
      }
    }
    vector <ul> go;
    for (int c1 = 0; c1 <= (int)nw.size(); ++c1) {
      for (auto mask : can) {
        for (int j = 0; j < c1; ++j) {
          mask |= (1LL << nw[j]);
        }   
        if (k >= K) {
          vector <int> ord;
          for (int j = 0; j < k; ++j) {
            ord.push_back((mask >> pos[j]) & 1);
          }
          sort(ord.begin(), ord.end());
          for (int j = 0; j < k; ++j) {
            mask &= ~(1LL << pos[j]);
            mask |= (1LL * ord[j]) << pos[j];
          }
          go.push_back(mask);
        } else {
          int nmask = 0;
          for (int j = 0; j < k; ++j) {
            int b = (mask >> pos[j]) & 1;
            nmask |= b << j;
          }
          nmask = sr[nmask];
          for (int j = 0; j < k; ++j) {
            int b = (nmask >> (k - j - 1)) & 1;
            mask &= ~(1LL << pos[j]);
            mask |= (1LL * b) << pos[j];
          }
          go.push_back(mask);
        }
      } 
    }
    sort(go.begin(), go.end());
    go.resize(unique(go.begin(), go.end()) - go.begin());
    can = go;
  }
  if (n == 1) {
    cout << "ACCEPTED\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      cout << "REJECTED\n";
      return 0;
    }
  }
  for (auto mask : can) {
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      ok &= ((mask >> i) & 1) >= ((mask >> (i - 1)) & 1);
    }
    if (!ok) {
      cout << "REJECTED\n";
      return 0;
    }
  }  
  cout << "ACCEPTED\n";
}
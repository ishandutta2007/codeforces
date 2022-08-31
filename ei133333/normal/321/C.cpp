#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int N;
vector< int > g[100000];
bool v[100000][30];
int t[100000];

int dfs(int idx, int par) {
  int ret = 0;
  vector< int > d(30);
  for(auto &to : g[idx]) {
    if(to != par) {
      ret = max(ret, dfs(to, idx));
      for(int i = 0; i < 30; i++) d[i] += v[to][i];
    }
  }
  int low = 0;
  for(int i = 29; i >= 0; i--) {
    if(d[i] >= 2) {
      low = i + 1;
      break;
    }
  }
  for(int i = low; i <= 30; i++) {
    if(i == 30) {
      throw 0;
    }
    bool correct = true;
    for(auto &to : g[idx]) {
      if(to != par) {
        if(v[to][i]) correct = false;
      }
    }
    if(correct) {
      ret = max(ret, i);
      t[idx] = i;
      v[idx][i] = true;
      for(auto &to : g[idx]) {
        if(to != par) {
          for(int j = i + 1; j < 30; j++) {
            v[idx][j] |= v[to][j];
          }
        }
      }
      break;
    }
  }
  return ret;
}

int main() {
  cin >> N;
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, -1);
  for(int i = 0; i < N; i++) {
    cout << (char) ('Z'-t[i]) << " ";
  }
  cout << endl;
}
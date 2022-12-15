#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 5005;

vector<int> v[30];
map<int, pair<int, int>> dic;
int sum[30];
pair<int, int> to[30][ms];
int temp[20];
int valid[35000];
int bef[35000];
vector<pair<int, int>> paths[35000];
pair<int, int> goes[20];

int get(int sm) {
  if(!bef[sm]) {
    for(auto j : paths[sm]) {
      int x = j.first;
      int y = j.second;
      goes[to[x][y].first] = {v[to[x][y].first][to[x][y].second],  x+1};
    }
  } else {
    get(bef[sm]); get(sm ^ bef[sm]);
  }
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int total = 0;
  for(int i = 0; i < n; i++) {
    int u;
    cin >> u;
    for(int j = 0; j < u; j++) {
      int k;
      cin >> k;
      sum[i] += k;
      v[i].emplace_back(k);
      dic[k] = {i, j};
    }
    total += sum[i];
  }
  if(total % n != 0) {
    cout << "No\n";
    return 0;
  }
  total = total / n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < v[i].size(); j++) {
      int w = total - sum[i] + v[i][j];
      if(dic.count(w)) to[i][j] = dic[w];
      else to[i][j] = {-1, -1};
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < v[i].size(); j++) {
      memset(temp, 0, sizeof temp);
      temp[i] = 1;
      vector<pair<int, int>> path = {{i, j}};
      auto cur = to[i][j];
      while(cur.first != -1 && !temp[cur.first]) {
        int u = cur.first;
        int v = cur.second;
        path.push_back(cur);
        temp[u] = 1;
        cur = to[u][v];
      }
      if(cur.first == i && cur.second == j) {
        int bm = 0;
        for(auto e : path) bm |= (1 << (e.first));
        if(!valid[bm]) paths[bm] = path;
        valid[bm] = 1;
      }
    }
  }
  for(int i = 3; i < (1 << n); i++) {
    for(int j = (i-1)&i; j && !valid[i]; j = (j-1)&i) {
      if(valid[j] && valid[i^j]) {
        valid[i] = 1;
        bef[i] = j;
      }
    }
      // cout << i << " is " << valid[i] << endl;
  }
  if(!valid[(1 << n)-1]) {
    cout << "No\n";
    return 0;
  }
  get((1 << n) -1 );
  cout << "Yes\n";
  for(int i = 0; i < n; i++) {
    cout << goes[i].first << ' ' << goes[i].second << '\n';
  }
}
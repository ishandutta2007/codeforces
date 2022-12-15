#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 2e6+5;;

vector<pair<int, int>> v;
int order[ms];
int visited[ms];

int query2(int i, int j, int k) {
  cout << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
  int x;
  cin >> x;
  return x;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int cur = 2;
  for(int i = 3; i <= n; i++) {
    cout << 2 << ' ' << 1 << ' ' << cur << ' ' << i << endl;
    int x;
    cin >> x;
    if(x < 0) cur = i;
  }
  order[0] = 1;
  order[1] = cur;
  visited[1] = 1;
  visited[cur] = 1;
  int k = 2;
  for(int i = 2; i <= n; i++) {
    if(i != cur) {
      int x;
      cout << 1 << ' ' << 1 << ' ' << cur << ' ' << i << endl;
      cin >> x;
      v.emplace_back(x, i);
    }
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size()-1; i++) {
    visited[i] = query2(1, v[v.size()-1].second, v[i].second);
    if(visited[i] < 0) order[k++] = v[i].second;
  }
  order[k++] = v[v.size()-1].second;
  for(int i = v.size() - 1; i > 0; i--) {
    if(visited[i-1] > 0) order[k++] = v[i-1].second;
  }
  cout << 0;
  for(int i = 0; i < n; i++) {
    cout << ' ' << order[i];
  }
  cout << endl;
}
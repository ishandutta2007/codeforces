#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int N;
vector< int > g[100000];
vector< int > sub;

int dfs(int idx) {
  int sum = g[idx].empty();
  for(auto &to : g[idx]) sum += dfs(to);
  sub.push_back(sum);
  return sum;
}

int main() {
  cin >> N;
  for(int i = 1; i < N; i++) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
  dfs(0);
  sort(begin(sub), end(sub));
  for(int i = 0; i < N; i++) {
    cout << sub[i] << " ";
  }
  cout << endl;
}
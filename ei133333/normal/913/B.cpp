#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 N;
  vector< int > g[1000];

  cin >> N;
  for(int i = 1; i < N; i++) {
    int x;
    cin >> x;
    --x;
    g[x].emplace_back(i);
  }

  for(int i = 0; i < N; i++) {
    if(g[i].empty()) {
      continue;
    }
    int sum = 0;
    for(auto& j : g[i]) {
      if(g[j].empty()) ++sum;
    }

    if(sum < 3) {
      cout << "No" << endl;
      return (0);
    }
  }

  cout << "Yes" << endl;
}
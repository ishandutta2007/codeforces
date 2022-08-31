#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, F[100000];
  vector< int > v[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> F[i];
    --F[i];
    v[F[i]].push_back(i);
  }

  int g[100000];
  vector< int > h;

  for(int i = 0; i < N; i++) {
    if(v[i].empty()) continue;
    bool flag = false;
    for(int j : v[i]) {
      if(i == j) {
        flag = true;
      }
      g[j] = h.size();
    }
    if(!flag) {
      cout << -1 << endl;
      exit(0);
    } else {
      h.push_back(i);
    }
  }

  cout << h.size() << endl;
  for(int i = 0; i < N; i++) {
    if(i > 0) cout << " ";
    cout << g[i] + 1;
  }
  cout << endl;
  for(int i = 0; i < h.size(); i++) {
    if(i > 0) cout << " ";
    cout << h[i] + 1;
  }
  cout << endl;
}
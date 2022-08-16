#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

void solve()
{
  int N, M, X[100];
  cin >> N >> M;
  for(int i = 0; i < M; i++) cin >> X[i], --X[i];

  int decide[100];
  memset(decide, -1, sizeof(decide));
  set< int > st;
  for(int i = 1; i < M; i++) {
    int sa = (X[i] - X[i - 1] + N) % N;
    if(sa == 0) sa += N;
    if(~decide[X[i - 1]]) {
      if(decide[X[i - 1]] != sa) {
        cout << -1 << endl;
        return;
      }
    } else {
      decide[X[i - 1]] = sa;
      if(st.count(sa)) {
        cout << -1 << endl;
        return;
      }
      st.emplace(sa);
    }
  }

  for(int i = 0; i < N; i++) {
    if(decide[i] == -1) {
      int row = 1;
      while(st.count(row)) row++;
      st.emplace(row);
      decide[i] = row;
    }
  }

  for(int i = 0; i < N; i++) {
    cout << decide[i] << " ";
  }
  cout << endl;

}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
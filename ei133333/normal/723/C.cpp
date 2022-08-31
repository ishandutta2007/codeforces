#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M, A[2000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int possible = N / M;

  vector< vector< int > > near(M + 1);
  vector< int > other;
  for(int i = 0; i < N; i++) {
    if(A[i] <= M) near[A[i]].push_back(i);
    else other.emplace_back(i);
  }

  for(int i = 1; i <= M; i++) {
    while(near[i].size() > possible) {
      other.emplace_back(near[i].back());
      near[i].pop_back();
    }
  }

  for(int i = 1; i <= M; i++) {
    while(near[i].size() < possible) {
      near[i].push_back(other.back());
      other.pop_back();
    }
  }


  int ans[2000];
  for(int i = 0; i < N; i++) ans[i] = A[i];
  for(int i = 1; i <= M; i++) {
    for(auto& k : near[i]) ans[k] = i;
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    ret += ans[i] != A[i];
  }
  cout << possible << " " << ret << endl;
  for(int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
}
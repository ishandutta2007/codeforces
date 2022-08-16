#include<bits/stdc++.h>

using namespace std;

struct Taplis
{
  void TapTap()
  {
    int N, A[200000];
    int sz[200000] = {};
    bool skiped[200000] = {};
    vector< int > appear[200000];

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &A[i]);
      --A[i];
      appear[A[i]].push_back(i);
      ++sz[A[i]];
    }

    int ret = 0;
    vector< int > unuse;
    vector< pair< int, int > > candidate;

    for(int i = N - 1; i >= 0; i--) {
      int cost = max(0, sz[i] - 1);
      ret += cost;
      if(sz[i] == 0) {
        unuse.push_back(i);
      } else if(sz[i] >= 2) {
        for(int j : appear[i]) {
          candidate.emplace_back(j, i);
        }
      }
    }

    sort(begin(candidate), end(candidate));
    for(auto &p : candidate) {
      if(sz[p.second] == 1) continue;
      if(skiped[p.second] || unuse.back() < p.second) {
        A[p.first] = unuse.back();
        --sz[p.second];
        unuse.pop_back();
      } else {
        skiped[p.second] = true;
      }
    }

    printf("%d\n", ret);
    for(int i = 0; i < N; i++) {
      printf("%d ", A[i] + 1);
    }
    puts("");

  }
};

int main()
{
  Taplis().TapTap();
}
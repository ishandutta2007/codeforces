#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int K;
  scanf("%d", &K);
  map< int64, pair< int, int > > exists;

  for(int i = 0; i < K; i++) {
    int N;
    scanf("%d", &N);
    vector< int > vs(N);
    int64 all = 0;
    for(int j = 0; j < N; j++) {
      scanf("%d", &vs[j]);
      all += vs[j];
    }
    for(int j = 0; j < N; j++) {
      int64 sub = all - vs[j];
      if(exists.count(sub)) {
        cout << "YES" << endl;
        cout << exists[sub].first << " " << exists[sub].second << endl;
        cout << i + 1 << " " << j + 1 << endl;
        return 0;
      }
    }
    for(int j =0 ; j < N; j++) {
      int64 sub = all - vs[j];
      exists[sub] = {i + 1, j + 1};
    }
  }
  cout << "NO" << endl;
}
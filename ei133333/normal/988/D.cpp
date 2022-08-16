#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, X[200000];

  cin >> N;
  set< int64 > exists;
  for(int i = 0; i < N; i++) {
    cin >> X[i];
    exists.emplace(X[i]);
  }
  sort(X, X + N);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    for(int64 sub = 2; sub <= (1LL << 32); sub <<= 1LL) {
      int sum = 2;
      for(int64 beet = sub; sum <= 3; beet <<= 1LL) {
        if(!exists.count(X[i] + beet)) break;
        ret = max(ret, sum);
        ++sum;
      }
    }

    {
      int sum = 1;
      for(int64 beet = 0; beet <= 2; beet++) {
        if(!exists.count(X[i] + beet)) break;
        ret = max(ret, sum);
        ++sum;
      }
    }
  }

  cout << ret << endl;


  for(int i = 0; i < N; i++) {
    for(int64 sub = 2; sub <= (1LL << 32); sub <<= 1LL) {
      int sum = 2;
      for(int64 beet = sub; sum <= 3; beet <<= 1LL) {
        if(!exists.count(X[i] + beet)) break;
        if(ret == sum) {
          cout << X[i] << " ";
          for(int64 k = sub; k <= beet; k <<= 1LL) cout << X[i] + k << " ";
          cout << endl;
          return 0;
        }
        ++sum;
      }
    }

    {
      int sum = 1;
      for(int64 beet = 0; beet <= 2; beet++) {
        if(!exists.count(X[i] + beet)) break;
        if(ret == sum) {
          for(int64 k = 0; k <= beet; k++) cout << X[i] + k << " ";
          cout << endl;
          return 0;
        }

        ++sum;
      }
    }
  }



}
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
  int N, L[200], R[200];
  cin >> N;

  for(int i = 0; i < N; i++) {
    int S, D;
    cin >> S >> D;

    L[i] = S, R[i] = S + D;
    bool match = true;
    for(int j = 0; j < i; j++) {
      if(L[j] >= R[i] || R[j] <= L[i]) continue;
      match = false;
    }
    if(!match) {
      vector< int > small;
      for(int j = 0; j < i; j++) small.push_back(R[j]);
      small.push_back(1);
      sort(begin(small), end(small));

      for(int val : small) {
        L[i] = val, R[i] = val + D;
        match = true;
        for(int j = 0; j < i; j++) {
          if(L[j] >= R[i] || R[j] <= L[i]) continue;
          match = false;
        }
        if(match) break;
      }
    }
    cout << L[i] << " " << R[i] - 1 << endl;

  }
}
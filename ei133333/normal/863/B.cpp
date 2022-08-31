#include <bits/stdc++.h>

using namespace std;

const int INF= 1 << 30;


int main()
{
  int N, A[100];

  cin >> N;
  N *= 2;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ret = INF;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      vector< int > vs;
      for(int k = 0; k < N; k++) {
        if(i == k || j == k) continue;
        vs.push_back(A[k]);
      }
      sort(begin(vs), end(vs));
      int cost = 0;
      for(int k = 1; k < vs.size(); k += 2) {
        cost += vs[k] - vs[k - 1];
      }
      ret = min(ret, cost);
    }
  }

  cout << ret << endl;
}
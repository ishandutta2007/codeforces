#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K[100001] = {};
  cin >> N;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    K[x]++;
  }
  for(int i = 1; i < 100001; i++) {
    K[i] += K[i - 1];
  }
  int Q;
  cin >> Q;
  while(Q--) {
    int m;
    cin >> m;
    cout << K[min(100000, m)] << endl;
  }
}
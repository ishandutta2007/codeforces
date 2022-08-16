#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int K, R[25];

int main()
{
  cin >> K;
  for(int i = 0; i < K; i++) {
    cin >> R[i];
  }
  sort(R, R + K);

  cout << max(R[K - 1] - 25, 0) << endl;
}
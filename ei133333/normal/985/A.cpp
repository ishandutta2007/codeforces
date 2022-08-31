#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

// 

int main() {
  int N, P[100];

  cin >> N;
  for(int i = 0; i < N / 2; i++) {
    cin >> P[i];
    --P[i];
  }
  sort(P, P + N / 2);

  int latte = 0, malta = 0;
  for(int i = 0; i < N / 2; i++) {
    latte += abs(2 * i - P[i]);
    malta += abs(2 * i + 1 - P[i]);
  }

  cout << min(latte, malta) << endl;
}
#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int64 N, K;
  cin >> N >> K;
  cout << (N * 8+K-1)/K + (N * 5+K-1)/K + (N * 2+K-1)/K << endl;
}
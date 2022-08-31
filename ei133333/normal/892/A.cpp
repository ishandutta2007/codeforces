#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, A[100000], B[100000];
  cin >> N;
  int64 add = 0;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    add += x;
  }
  for(int i = 0; i < N; i++) cin >> B[i];
  sort(B, B + N);
  if(add <= B[N - 1] + B[N - 2]) cout << "YES\n";
  else cout << "NO\n";
}
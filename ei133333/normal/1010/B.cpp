#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 M, N;
  cin >> M >> N;
  int A[30];
  for(int i = 0; i < N; i++) {
    cout << 1 << endl;
    int p;
    cin >> p;
    if(p == 0) return 0;
    if(p == 1) A[i] = 1; // 1
    else A[i] = 0;
  }
  int64 ok = 1, ng = M + 1;
  int pos = 0;
  while(ng - ok > 1) { // 0
    int64 mid = (ok + ng) / 2;
    cout << mid << endl;
    int p;
    cin >> p;
    if(p == 0) return 0;
    if(A[pos] == 0) p *= -1;
    pos = (pos + 1) % N;
    if(p >= 0) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
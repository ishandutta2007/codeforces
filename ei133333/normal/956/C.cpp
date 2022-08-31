#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M[100000];

  cin >> N;
  int width = 0;
  for(int i = 0; i < N; i++) {
    cin >> M[i];
  }

  int needLine[100000] = {};
  needLine[0] = 1;
  for(int i = 1; i < N; i++) {
    needLine[i] = max(M[i] + 1, needLine[i - 1]);
  }
  for(int i = N - 2; i >= 0; i--) {
    if(needLine[i] + 1 < needLine[i + 1]) {
      needLine[i] = needLine[i + 1] - 1;
    }
  }
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    ret += needLine[i] - M[i] - 1;
  }
  cout << ret << endl;
}
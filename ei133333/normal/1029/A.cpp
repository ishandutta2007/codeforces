#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, K;
  string T;

  cin >> N >> K;
  cin >> T;

  string two = T;
  for(int i = N - 1; i >= 1; i--) {
    if(T.find(T.substr(i)) == 0) two = T.substr(N - i);
  }
  for(int i = 1; i < K; i++) T += two;
  cout << T << endl;
}
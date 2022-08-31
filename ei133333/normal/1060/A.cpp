#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int add = 0;
  for(int i = 0; i < N; i++) {
    if(S[i] == '8') ++add;
  }
  cout << min(add, N / 11) << endl;
}
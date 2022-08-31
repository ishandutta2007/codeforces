#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N;
  cin >> N;
  int latte[2][100000] = {{}}, beet[100000];
  for(int i = 0; i < N; i++) {
    cin >> beet[i];
    for(int j = 2; j <= 3; j++) {
      while(beet[i] % j == 0) {
        beet[i] /= j;
        latte[j - 2][i]++;
      }
    }
  }
  bool same = true;
  for(int i = 1; i < N; i++) {
    same &= beet[i] == beet[i - 1];
  }
  if(same) puts("Yes");
  else puts("No");
}
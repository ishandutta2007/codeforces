#include <bits/stdc++.h>

using namespace std;

int main() {
  int Y, B, R;
  cin >> Y >> B >> R;

  int ret = 0;
  for(int i = 0; i <= Y; i++) {
    for(int j = 0; j <= B; j++) {
      for(int k = 0; k <= R; k++) {
        if(i + 1 == j && j + 1 == k) {
          ret = max(ret, i + j + k);
        }
      }
    }
  }
  cout << ret << endl;
}
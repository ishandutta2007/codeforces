#include <iostream>
#include <vector>

using namespace std;

int main() {
  int q, i, j;
  cin >> q;
  for(int l = 0; l < q; ++l) {
    cin >> i >> j;
    if((j - i) % 2 == 1) {
      if(i % 2 == 0) cout << -((j - i) / 2 + 1) << endl;
      else cout << (j - i) / 2 + 1 << endl;
    }
    else {
      if(i % 2 == 0) cout << j - (j - i) / 2 << endl;
      else cout << (j - i) / 2 - j << endl;
    }
  }
}
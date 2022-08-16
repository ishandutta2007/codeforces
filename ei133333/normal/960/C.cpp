#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 X, D;
  int64 po[32];
  po[0] = 1;
  for(int i = 1; i < 32; i++) po[i] = po[i - 1] * 2;
  for(int i = 1; i < 32; i++) po[i]--;

  cin >> X >> D;
  int64 base = 1;
  vector< int64 > ans;
  while(X > 0) {
    for(int64 i = 30; i >= 0; i--) {
      if(po[i] <= X) {
        X -= po[i];
        for(int j = 0; j < i; j++) {
          ans.emplace_back(base);
        }
        break;
      }
    }
    base += D;
  }

  cout << ans.size() << endl;
  for(auto& p : ans) cout << p << " ";
  cout << endl;

}
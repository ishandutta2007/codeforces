// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto ask = [&](int x, int y, int mood) {
    if (mood == 1) {
      cout << "AND";
    } else if (mood == 2) {
      cout << "OR";
    } else {
      cout << "XOR";
    }
    
    cout << ' ' << x + 1 << ' ' << y + 1 << endl;
    int res;
    cin >> res;
    return res;
  };

  vector<int> x(n);
  for (int i = 0; i < n - 1; ++i) {
    x[i + 1] = ask(0, i + 1, 0);
  }
  int ex = ask(0, 2, 2);
  int ex2 = ask(1, 2, 2);

  int res = ask(0, 1, 1);
  for (int i = 0; i < 32; ++i) {
    if (!bool(x[1] & (1 << i))) {
      continue;    
    }
    int bit = (1 << i);
    if (x[2] & bit) {
      if (ex2 & bit) {
        continue;
      } else {
        res += bit;
      }
    } else {
      if (ex & bit) {
        res += bit;  
      } else {
        continue;
      }
    }
  }

  cout << "! " << res << ' ';
  for (int i = 1; i < n; ++i) {
    cout << (res ^ x[i]) << ' ';  
  }
  cout << endl;
}
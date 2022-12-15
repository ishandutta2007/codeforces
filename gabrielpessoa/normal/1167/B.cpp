#include <bits/stdc++.h>
using namespace std;

vector<int> v = {4, 8, 15, 16, 23, 42};

int main() {
  int a, b, c, d;
  cout << "? 1 2" << endl;
  cin >> a;
  cout << "? 1 3" << endl;
  cin >> b;
  cout << "? 4 5" << endl;
  cin >> c;
  cout << "? 4 6" << endl;
  cin >> d;
  do {
    if(v[0] * v[1] == a && v[0] * v[2] == b && v[3] * v[4] == c && v[3] * v[5] == d) {
      cout << "!";
      for(int x : v) cout << " " << x;
      cout << endl;
      return 0;
    }
  } while(next_permutation(v.begin(), v.end()));
}
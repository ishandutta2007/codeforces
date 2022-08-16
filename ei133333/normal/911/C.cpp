#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main()
{

  vector< int > v(3);
  cin >> v[0] >> v[1] >> v[2];
  sort(begin(v), end(v));

  if(v[0] == 1) {
    cout << "YES" << endl;
    return (0);
  }
  if(v[0] == 2 && v[1] == 2) {
    cout << "YES" << endl;
    return (0);
  }
  if(v[0] == 2 && v[1] == 4 && v[2] == 4) {
    cout << "YES" << endl;
    return (0);
  }
  if(v[0] == 3 && v[1] == 3 && v[2] == 3) {
    cout << "YES" << endl;
    return (0);
  }

  cout << "NO" << endl;

}
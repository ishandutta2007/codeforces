#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int >;
const int mod = 1e9 + 7;

int main()
{
  int N;
  cin >> N;

  int a = 1, b = 2, c = 3;
  for(int i = 0; i < N; i++) {
    int k;
    cin >> k;
    if(a == k) {
      swap(b, c);
    } else if(b == k) {
      swap(a, c);
    } else {
      cout << "NO" << endl;
      return(0);
    }
  }

  cout << "YES" << endl;

}
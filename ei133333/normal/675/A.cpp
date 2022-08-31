#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 A, B, C;
  cin >> A >> B >> C;

  B -= A;
  A -= A;

  if(A == B) {
    cout << "YES" << endl;
  } else if(C == 0) {
    cout << "NO" << endl;
  } else if(C > 0 && A > B) {
    cout << "NO" << endl;
  } else if(C < 0 && A < B) {
    cout << "NO" << endl;
  } else if(B % abs(C) == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
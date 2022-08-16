#include <bits/stdc++.h>

using namespace std;

int main()
{
  int A, B;
  cin >> A >> B;
  if(A == 0 && B == 0) {
    cout << "NO" << endl;
  } else if(abs(A - B) <= 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
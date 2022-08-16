#include<bits/stdc++.h>

using namespace std;

int main()
{
  int A;
  cin >> A;

  if(A == 1) {
    cout << 1 << " " << 1 << endl;
    cout << 1 << endl;
  } else {
    cout << (A - 1) * 2 << " " << 2 << endl;
    cout << 1 << " " << 2 << endl;
  }

}
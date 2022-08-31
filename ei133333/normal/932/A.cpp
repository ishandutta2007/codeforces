#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  string A;
  cin >> A;
  string B = A;
  reverse(begin(B), end(B));
  cout << A << B << endl;
}
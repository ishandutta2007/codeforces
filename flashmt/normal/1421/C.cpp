#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  cout << 4 << endl;
  cout << "R " << n - 1 << endl;
  cout << "L " << 2 << endl;
  cout << "R " << 2 << endl;
  cout << "R " << n * 2 + 1 << endl;
}
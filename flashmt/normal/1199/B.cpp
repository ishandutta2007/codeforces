#include <bits/stdc++.h>
using namespace std;

int main()
{
  double h, l;
  cin >> h >> l;
  cout << fixed << setprecision(9) << (h * h + l * l) / h / 2 - h << endl;
}
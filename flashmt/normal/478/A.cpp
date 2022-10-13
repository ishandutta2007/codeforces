#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x, sum = 0;
  for (int i = 0; i < 5; i++)
  {
    cin >> x;
    sum += x;
  }
  cout << (sum % 5 == 0 && sum / 5 ? sum / 5 : -1) << endl;
}
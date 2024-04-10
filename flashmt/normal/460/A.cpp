#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int prev = 0;
  while (1)
  {
    int newSock = n / m - prev / m;
    prev = n;
    n += newSock;
    if (!newSock) break;
  }
  cout << n << endl;
}
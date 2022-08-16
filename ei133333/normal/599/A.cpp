#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

int main()
{
  int D1, D2, D3;
  cin >> D1 >> D2 >> D3;
  cout << min({D1 + D2 + D3, (D1 + D3) << 1, (D2 + D3) << 1, (D1 + D2) << 1}) << endl;
}
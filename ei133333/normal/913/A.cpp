#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  int base = 1;
  for(int i = 0; i < min(N, 30); i++) base *= 2;
  cout << M % base << endl;
}
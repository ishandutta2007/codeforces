#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N;
  cin >> N;
  N++;
  int64 fact = 1;
  while(fact * 10 < N) fact *= 10;
  int64 M = (N + fact - 1) / fact * fact;
  cout << M - N + 1 << endl;
}
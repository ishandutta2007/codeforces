#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, M;
  cin >> N >> M;
  int64 latte = N / M;
  latte = latte * (latte - 1) / 2 * (M - N % M) + latte * (latte + 1) / 2 * (N % M);
  int64 malta = N - (M - 1);
  malta = malta * (malta - 1) / 2;
  cout << latte << " " << malta << endl;
}
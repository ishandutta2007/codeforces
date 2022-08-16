#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 calc(int64 N)
{
  if(N % 2 == 1) return (1);
  return (1 + calc(N / 2));
}

int main()
{
  int64 N, K;
  cin >> N >> K;
  cout << calc(K) << endl;
}
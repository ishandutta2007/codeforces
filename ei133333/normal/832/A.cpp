#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, K;
  cin >> N >> K;

  int64 fact = N / K;
  if(fact % 2 == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
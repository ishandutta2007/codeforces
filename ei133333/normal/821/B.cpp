#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int B, M;
  cin >> M >> B;
  int64 ret = 0;

  auto sum = [&](int x)
  {
    return (1LL * x * (x + 1) / 2);
  };

  for(int i = 0; i <= B; i++) {
    int j = M * B - M * i;
    ret = max(ret, sum(i) * (j + 1) + sum(j) * (i + 1));
  }

  cout << ret << endl;
}
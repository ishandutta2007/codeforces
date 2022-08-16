#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int main()
{
  int64 N, M;
  cin >> N >> M;
  int64 ret = 0;
  for(int64 i = 0; i <= 4; i++) {
    int64 count1 = (N + 4 - i) / 5;
    int64 count2 = (M + (i + 1) % 5) / 5;
    ret += count1 * count2;
  }
  cout << ret << endl;
}
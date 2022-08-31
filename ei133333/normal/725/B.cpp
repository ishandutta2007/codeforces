#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

string t = "fedabc";

int main()
{
  // 1, 3
  // 2, 4
  // 5, 7
  // 6, 8

  int64 N;
  char c;

  scanf("%lld%c", &N, &c);
  int pos = t.find(c);

  int64 roll = (N - 1) / 2;
  if((N - 1) % 4 == 1) ++roll;
  else if((N - 1) % 4 == 2) --roll;
  if((N - 1) % 4 < 2) {
    cout << roll * 6 + pos + 1 + (N - 1) << endl;
  } else {
    cout << roll * 6 + pos + 1 + (N - 3) << endl;
  }
}
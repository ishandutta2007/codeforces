#include<bits/stdc++.h>

using namespace std;

int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int ret = 0;
  while(A > 0 && C > 0 && D > 0) {
    --A, --C, --D;
    ret += 256;
  }
  while(A > 0 && B > 0) {
    --A, --B;
    ret += 32;
  }

  cout << ret << endl;
}
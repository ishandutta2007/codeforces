#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, H;
  cin >> N >> H;

  int ret = 0;
  while(N--) {
    int a;
    cin >> a;
    ++ret;
    if(a > H) ++ret;
  }
  cout << ret << endl;
}
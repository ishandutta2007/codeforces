#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, a[2] = {};
  cin >> N;
  long long ret = 0;
  for(int i = 1; i <= N; i++) {
    cin >> a[i & 1];
    ret += llabs(a[1] - a[0]);
  }
  cout << ret << endl;
}
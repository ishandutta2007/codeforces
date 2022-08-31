#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int N;
  cin >> N;
  int ret = 0;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    ret = max(ret, min(x - 1, 1000000 - x));
  }
  cout << ret << endl;
}
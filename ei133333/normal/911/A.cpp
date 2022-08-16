#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main()
{
  int N, A[100000];

  cin >> N;
  int mx = INF;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    mx = min(mx, A[i]);
  }

  int last = -1;
  int ret = INF;
  for(int i = 0; i < N; i++) {
    if(mx == A[i]) {
      if(~last) ret = min(ret, i - last);
      last = i;
    }
  }

  cout << ret << endl;
}
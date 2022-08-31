#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, D;
  string S;

  cin >> N >> D;
  cin >> S;
  int f[101];
  memset(f, -1, sizeof(f));
  f[0] = 0;
  for(int i = 1; i < N; i++) {
    if(S[i] == '1') {
      for(int j = 1; j <= D; j++) {
        if(i - j >= 0 && ~f[i - j]) {
          if(f[i] == -1) f[i] = f[i - j] + 1;
          else f[i] = min(f[i], f[i - j] + 1);
        }
      }
    }
  }

  cout << f[N - 1] << endl;
}
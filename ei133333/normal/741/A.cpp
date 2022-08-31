#include <bits/stdc++.h>

using namespace std;

int N, crush[100];
int connection[100];
int sz[100];

int main()
{
  memset(connection, -1, sizeof(connection));

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> crush[i];
    crush[i]--;
  }

  for(int i = 0; i < N; i++) {
    if(~connection[i]) continue;
    int now = i;
    while(connection[now] == -1) {
      connection[now] = i;
      ++sz[i];
      now = crush[now];
    }
    if(now != i) {
      cout << -1 << endl;
      exit(0);
    }
  }

  long long ret = 1;
  for(int i = 0; i < N; i++) {
    if(connection[i] == i) {
      if(sz[i] % 2 == 0) sz[i] /= 2;
      ret = 1LL * ret / __gcd(ret, (long long) sz[i]) * sz[i];
    }
  }
  cout << ret << endl;
}
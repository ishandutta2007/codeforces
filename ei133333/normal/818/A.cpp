#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

void solve()
{
  int64 N, K;
  cin >> N >> K;

  int64 cur = (N / 2) / (K + 1);

  N -= cur;
  cout << cur << " ";
  N -= cur * K;
  cout << cur * K << " ";
  cout << N << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
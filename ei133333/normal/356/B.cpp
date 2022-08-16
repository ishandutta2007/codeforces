#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

string S, T;
int64 N, M;
int64 latte[26][1000001];

int main()
{
  cin >> N >> M;
  cin >> S >> T;

  int gcd = __gcd((int) S.size(), (int) T.size());
  for(int i = 0; i < S.size(); i++) {
    ++latte[S[i] - 'a'][i % gcd];
  }
  int64 ret = 0;
  int64 times = (int) S.size() / gcd;
  for(int i = 0; i < T.size(); i++) {
    ret += times - latte[T[i] - 'a'][i % gcd];
  }
  ret *= M / times;
  cout << ret << endl;
}
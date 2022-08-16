#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N, K;
  cin >> N >> K;
  map< int64, int > beet;
  for(int i = 0; i < N; i++) {
    int64 a;
    cin >> a;
    beet[a]++;
  }
  int64 ret = 0;
  K *= 2;
  for(auto &p : beet) {
    while(K < p.first) K *= 2, ++ret;
    K = max(K, p.first * 2);
  }
  cout << ret << endl;
}
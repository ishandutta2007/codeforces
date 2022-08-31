#include<bits/stdc++.h>

using namespace std;

typedef long long int64;


map< int64, int > dp[61];

int f(int64 zan, int64 bit)
{
  if(zan == 0) return (0);
  if(dp[zan].count(bit)) return (dp[zan][bit]);

  set< int > x;
  for(int64 i = 1; i <= zan; i++) {
    if((bit >> i) & 1) continue;
    x.emplace(f(zan - i, bit | (1LL << i)));
  }
  int z = 0;
  while(x.count(z)) z++;
  return (dp[zan][bit] = z);
}

int main()
{
  int v[61] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

  int N;
  cin >> N;

  int xo = 0;
  for(int i = 0; i < N; i++) {
    int s;
    cin >> s;
    xo ^= v[s];
  }

  if(xo == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

}
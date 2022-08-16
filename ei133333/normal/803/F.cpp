#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int mod = 1e9 + 7;

int64 fact[100001];
int64 arr[100001];

int main()
{
  fact[0] = 1;
  for(int i = 1; i < 100001; i++) (fact[i] = fact[i - 1] * 2) %= mod;

  int N, A[100000];
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int64 ret = fact[N] - 1;
  int64 add = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] == 1) {
      continue;
    }
    vector< int > v;
    int tmp = A[i];
    for(int j = 2; j * j <= tmp; j++) {
      if(tmp % j == 0) v.push_back(j);
      while(tmp % j == 0) tmp /= j;
    }
    if(tmp > 1) v.push_back(tmp);

    int sz = v.size();
    for(int bit = 1; bit < 1 << sz; bit++) {
      int odd = 1;
      int n = 1;
      for(int j = 0; j < sz; j++) {
        if((bit >> j) & 1) odd *= -1, n *= v[j];
      }
      int64 beet = odd * arr[n];
      if(odd < 0) (ret += 2 * mod - fact[arr[n]]) %= mod;
      else (ret += fact[arr[n]]) %= mod;
      arr[n]++;
    }
  }
  cout << ret << endl;
}
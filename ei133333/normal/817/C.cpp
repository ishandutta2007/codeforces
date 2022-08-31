#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int64 T;
string S;

unordered_map< int64, int64 > dp[19][2];
int64 dp2[19][2];
unsigned long long mod_pow[19];

int64 rec2(int idx, bool free)
{
  if(idx == S.size()) return (1);
  if(~dp2[idx][free]) return (dp2[idx][free]);
  int end = free ? 9 : S[idx] - '0';
  int64 ret = 0;
  for(int i = 0; i <= end; i++)
    ret += rec2(idx + 1, free | (i != end));
  return (dp2[idx][free] = ret);
}

int64 rec(int idx, bool free, int64 ketasum, int64 oddsum)
{
  if(idx == S.size()) return (oddsum - ketasum >= T);
  if(oddsum - ketasum >= T) return (rec2(idx, free));
  if(dp[idx][free].count(oddsum - ketasum)) return (dp[idx][free][oddsum - ketasum]);
  if(oddsum + (mod_pow[S.size() - idx] - 1) - (ketasum + 1) < T) return (0);
  int end = free ? 9 : S[idx] - '0';
  int64 ret = 0;
  for(int i = 0; i <= end; i++)
    ret += rec(idx + 1, free | (i != end), ketasum + i, oddsum + i * mod_pow[S.size() - idx - 1]);
  return (dp[idx][free][oddsum - ketasum] = ret);
}

int main()
{
  memset(dp2, -1, sizeof(dp2));
  mod_pow[0] = 1;
  for(int i = 1; i < 19; i++) mod_pow[i] = mod_pow[i - 1] * 10;
  cin >> S >> T;
  cout << rec(0, false, 0, 0) << endl;
}
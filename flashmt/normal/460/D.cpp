#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

long long ans;
vector <long long> bestSet;

void brute(long long l, long long r, int k)
{
  for (int mask = 1; mask < 1 << (r - l + 1); mask++)
  {
    if (__builtin_popcount(mask) > k) continue;
    
    vector <long long> set;
    for (int i = 0; i <= r - l + 1; i++)
      if (mask >> i & 1)
        set.push_back(l + i);
    
    long long sumXor = 0;
    for (int i = 0; i < int(set.size()); i++) sumXor ^= set[i];
    if (sumXor < ans)
    {
      ans = sumXor;
      bestSet = set;
    }
  }
}

void solve2(long long l, long long r)
{
  for (long long i = l; i < r && ans > 1; i++)
    if ((i ^ (i + 1)) < ans)
    {
      ans = i ^ (i + 1);
      bestSet.clear();
      bestSet.push_back(i);
      bestSet.push_back(i + 1);
    }
}

void solve3(long long l, long long r)
{
  for (int i = 2; i <= 40; i++)
  {
    long long a = 3LL << (i - 2);
    long long b = (2LL << (i - 2)) + (1LL << (i - 2)) - 1;
    long long c = (1LL << (i - 1)) - 1;
    if (a <= r && c >= l)
    {
      ans = 0;
      bestSet.clear();
      bestSet.push_back(c);
      bestSet.push_back(b);
      bestSet.push_back(a);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  long long l, r;
  int k;
  cin >> l >> r >> k;
  
  ans = l;
  bestSet.push_back(l);
  
  if (r - l + 1 <= 16) brute(l, r, k);
  else if (k >= 4)
  {
    l = l + 4 - l % 4;
    cout << 0 << endl << 4 << endl;
    for (int i = 0; i < 4; i++) cout << l + i << ' ';
    return 0;
  }
  else 
  {
    if (k >= 2) solve2(l, r);
    if (k == 3) solve3(l, r);
  }
  
  cout << ans << endl << bestSet.size() << endl;
  for (int i = 0; i < int(bestSet.size()); i++) cout << bestSet[i] << ' ';
}
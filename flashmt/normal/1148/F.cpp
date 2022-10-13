#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n, val[300300];
  long long mask[300300], sumVal = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> val[i] >> mask[i];
    sumVal += val[i];
  }
 
  long long ans = 0;
  vector<int> parity(n, 0);
  for (int bit = 0; bit < 62; bit++)
  {
    long long sumChange = 0;
    for (int i = 0; i < n; i++)
      if (mask[i] == 1LL << bit)
        sumChange += (parity[i] ? -val[i] : val[i]);
 
    int pick;
    if (sumVal > 0) pick = sumChange > 0;
    else pick = sumChange < 0;
 
    for (int i = 0; i < n; i++)
      if (mask[i] >> bit & 1)
      {
        mask[i] ^= 1LL << bit;
        parity[i] ^= pick;
      }
 
    if (pick)
      ans |= 1LL << bit;
  }
 
  cout << ans << endl;
}
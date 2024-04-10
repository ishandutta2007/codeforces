#include <bits/stdc++.h>
using namespace std;
const int BIT = 32;
const int HALF_BIT = BIT / 2;
const int HALF_MASK = (1 << HALF_BIT) - 1;

vector <unsigned int> a[BIT], b[BIT];
string s, t;
int countBit[1 << (BIT / 2)];

vector <unsigned int> compress(string s, int offset)
{
  vector <unsigned int> res;
  if (offset >= s.size()) return res;
  
  int len = (s.size() - offset + BIT - 1) / BIT;
  for (int i = 0; i < len; i++)
  {
    unsigned int x = 0;
    for (int j = 0; j < BIT; j++)
    {
      x <<= 1;
      if (i * BIT + j + offset < s.size()) x |= s[i * BIT + j + offset] - '0';
    }
    res.push_back(x);
  }
  
  return res;
}

int query(int x, int y, int len)
{
  int res = 0, rx = x % BIT, ry = y % BIT;
  int ix = x / BIT, iy = y / BIT, full = len / BIT;
  
  for (int i = 0; i < full; i++)
  {
    unsigned int mask = a[rx][ix + i] ^ b[ry][iy + i];
    res += countBit[mask & HALF_MASK] + countBit[mask >> HALF_BIT];
  }
  
  if (len % BIT)
  {
    unsigned int mask = (a[rx][ix + full] ^ b[ry][iy + full]) >> (BIT - len % BIT);
    res += countBit[mask & HALF_MASK] + countBit[mask >> HALF_BIT];
  }
  
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> s >> t;
  for (int offset = 0; offset < BIT; offset++)
  {
    a[offset] = compress(s, offset);
    b[offset] = compress(t, offset);
  }
  
  for (int mask = 0; mask <= HALF_MASK; mask++) 
    countBit[mask] = __builtin_popcount(mask);

  int Q, x, y, len;
  cin >> Q;
  while (Q--)
  {
    cin >> x >> y >> len;
    cout << query(x, y, len) << '\n';
  }
}
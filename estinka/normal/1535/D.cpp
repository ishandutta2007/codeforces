#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string s;
vector<int> sum;
int k, q;
void calc(int vr)
{
  if (vr >= (1 << (k - 1)) - 1) 
  {  
    sum[vr] = 1 + (s[vr] == '?');
    return;
  }
  int l = vr * 2 + 2, r = vr * 2 + 1;
  sum[vr] = 0;
  if (s[vr] != '1') // left can win
    sum[vr] += sum[l];
  if (s[vr] != '0')
    sum[vr] += sum[r];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> s;
  sum.resize((1 << k) - 1, 0);
  reverse(s.begin(), s.end());
  for (int i = (1 << k) - 1; i>=0; i--) calc(i);
  cin >> q;
  while (q--)
  {
    int p; char c;
    cin >> p >> c;
    p = (1 << k) - 1 - p;
    s[p] = c;
    calc(p);
    while (p)
    {
      p = (p - 1)/ 2;
      calc(p);
    }
    cout << sum[0] << "\n";
  }
  return 0;
}
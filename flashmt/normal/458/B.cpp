#include <bits/stdc++.h>
using namespace std;
const unsigned long long oo = (unsigned long long)1e19;

int m, n, a[100100], b[100100];
unsigned long long sumA[100100], sumB[100100];

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> m >> n;
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  
  sort(a, a + m);
  sort(b, b + n);
  for (int i = 0; i < m; i++) sumA[i + 1] = sumA[i] + a[i];
  for (int i = 0; i < n; i++) sumB[i + 1] = sumB[i] + b[i];
  
  unsigned long long ans = oo;
  for (int i = n - 1; i >= 0; i--)
    ans = min(ans, sumA[m] * (n - i) + sumB[i]);
    
  for (int i = m - 1; i >= 0; i--)
    ans = min(ans, sumB[n] * (m - i) + sumA[i]);
    
  cout << ans << endl;
}
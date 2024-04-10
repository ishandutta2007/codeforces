#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  map<int, char> m;
  m[0] = 'D';
  m[1] = 'A';
  m[2] = 'C';
  m[3] = 'B';
  
  cin >> n;
  char ans = m[n % 4];
  int bestA = 0;
  for (int i = 1; i <= 2; i++)
    if (m[(n + i) % 4] < ans)
    {
      ans = m[(n + i) % 4];
      bestA = i;
    }
  
  cout << bestA << ' ' << ans << endl;
}
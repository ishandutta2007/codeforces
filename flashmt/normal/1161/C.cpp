#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  map <int, int> cnt;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    cnt[x]++;
  }
  cout << (cnt.begin()->second <= n / 2 ? "Alice" : "Bob") << endl;
}
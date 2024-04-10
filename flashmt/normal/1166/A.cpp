#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, cnt[128] = {0};
  string s;
  cin >> n;
  while (n--)
  {
    cin >> s;
    cnt[s[0]]++;
  }

  function<int(int)> countPair = [&] (int x) {
    return x * (x - 1) / 2;
  };

  int ans = 0;
  for (char c = 'a'; c <= 'z'; c++)
    ans += countPair(cnt[c] / 2) + countPair(cnt[c] - cnt[c] / 2);
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, cnt[3] = {0}, x;
  cin >> n;
  while (n--)
  {
    cin >> x;
    cnt[x]++;
  }

  if (cnt[1] && cnt[2])
  {
    cout << "2 1 ";
    cnt[1]--;
    cnt[2]--;
  }

  for (int i = 2; i; i--)
    while (cnt[i]--)
      cout << i << ' ';
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      cnt[a[i]]++;
    }

    int mode = 0;
    for (int i = 1; i <= n; i++)
      if (cnt[i] > cnt[mode])
        mode = i;

    if (cnt[mode] > (n + 1) / 2)
    {
      cout << "-1\n";
      continue;
    }

    int block = 0;
    vector<int> endpoint(n + 1, 0);
    for (int i = 0; i < n;)
    {
      int j = i + 1;
      while (j < n && a[j] != a[j - 1])
        j++;

      endpoint[a[i]]++;
      endpoint[a[j - 1]]++;
      block++;
      i = j;
    }

    int maxEndpoint = *max_element(endpoint.begin(), endpoint.end());
    cout << block - 1 + max(0, maxEndpoint - block - 1) << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  k--;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a.push_back({x, i});
  }

  sort(a.begin(), a.end(), greater<pair<int, int>>());
  set<int> s;
  s.insert(-1);
  s.insert(n);

  long long ans = 0;
  for (auto [x, id] : a)
  {
    auto it = s.lower_bound(id);
    assert(it != s.end() && it != s.begin());
    int r = *it - 1;
    int l = *(--it) + 1;
    s.insert(id);

    long long rMod = (r % k + k - id % k) % k;
    // [0, rMod] = rRepeat, (rMod, k) = rRepeat - 1 (after shift id % k)
    long long rRepeat = (r - id) / k + 1;
    long long lMod = (l % k + k - id % k) % k;
    long long lRepeat = (id - l) / k + 1;

    long long occurrences = lRepeat * rRepeat % BASE;
    if (!lMod) // l % k == id % k
    {
      occurrences = (occurrences + rMod * rRepeat % BASE * (lRepeat - 1)) % BASE;
      occurrences = (occurrences + (k - 1 - rMod) * (rRepeat - 1) % BASE * (lRepeat - 1)) % BASE;
    }
    else if (lMod <= rMod)
    {
      occurrences = (occurrences + (lMod - 1) * rRepeat % BASE * (lRepeat - 1)) % BASE;
      occurrences = (occurrences + (rMod - lMod + 1) * rRepeat % BASE * lRepeat) % BASE;
      occurrences = (occurrences + (k - 1 - rMod) * (rRepeat - 1) % BASE * lRepeat) % BASE;
    }
    else // lMod > rMod
    {
      occurrences = (occurrences + rMod * rRepeat % BASE * (lRepeat - 1)) % BASE;
      occurrences = (occurrences + (lMod - 1 - rMod) * (rRepeat - 1) % BASE * (lRepeat - 1)) % BASE;
      occurrences = (occurrences + (k - lMod) * (rRepeat - 1) % BASE * lRepeat) % BASE;
    }

    occurrences = (occurrences - 1 + BASE) % BASE;
    ans = (ans + occurrences * x) % BASE;
  }

  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n;
  long long s[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  sort(s, s + n);
  n = unique(s, s + n) - s;
  
  map <long long,int> distCount;
  for (int i = 1; i < n; i++)
    distCount[s[i] - s[i - 1]]++;
  
  vector <long long> marks(1, 0), sums(1, n);
  vector <int> overlaps(1, 0);
  long long mark = 0, sum = n;
  int overlap = 0;
  for (auto u : distCount)
  {
    sum += (u.first - mark - 1) * (n - overlap);
    mark = u.first;
    overlap += u.second;
    sum += n - overlap;

    marks.push_back(mark);
    sums.push_back(sum);
    overlaps.push_back(overlap);
  }

  int q;
  long long l, r;
  cin >> q;
  while (q--)
  {
    cin >> l >> r;
    r -= l;
    int id = upper_bound(marks.begin(), marks.end(), r) - marks.begin();
    id--;
    long long ans = sums[id] + (r - marks[id]) * (n - overlaps[id]);
    cout << ans << ' ';
  }
}
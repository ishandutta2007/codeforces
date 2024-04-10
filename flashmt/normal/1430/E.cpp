#include <bits/stdc++.h>
using namespace std;

int n, tree[200200];
queue<int> id[26];

void add(int x)
{
  for (int i = x; i <= n; i += i & -i)
    tree[i]++;
}

int get(int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res += tree[i];
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    id[s[i] - 'a'].push(i);

  reverse(s.begin(), s.end());
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    int curId = id[s[i] - 'a'].front();
    id[s[i] - 'a'].pop();
    ans += i - get(curId + 1);
    add(curId + 1);
  }

  cout << ans << endl;
}
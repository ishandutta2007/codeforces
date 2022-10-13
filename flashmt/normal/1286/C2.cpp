#include <bits/stdc++.h>
using namespace std;

vector<string> ask(int l, int r)
{
  cout << "? " << l << ' ' << r << endl;
  cout.flush();
  vector<string> resp;
  for (int i = l; i <= r; i++)
    for (int j = i; j <= r; j++)
    {
      string s;
      cin >> s;
      resp.push_back(s);
    }
  return resp;
}

void answer(vector<int> ans)
{
  cout << "! ";
  for (int x : ans)
    cout << char(x + 'a');
  cout << endl;
  cout.flush();
  exit(0);
}

// construct answer for [0, n), a[i] and a[n - 1 - i] might be swapped
vector<int> construct(int n, vector<string> resp, int knownIndex, int knownValue)
{
  vector<int> ans(n, 0);
  ans[knownIndex] = knownValue;
  int cnt[111][26] = {0};
  for (auto s : resp)
  {
    int len = s.size();
    for (auto c : s)
      cnt[len][c - 'a']++;
  }

  cnt[2][knownValue]--;
  for (int c = 0; c < 26; c++)
    if (cnt[2][c] % 2)
      ans[n - 1 - knownIndex] = c; // knownIndex is either 0 or n - 1

  for (int len = 3, l = 1, r = n - 2; l <= r; len++, l++, r--)
  {
    for (int i = 0; i < l; i++)
    {
      cnt[len][ans[i]] -= i + 1;
      cnt[len][ans[n - 1 - i]] -= i + 1;
    }

    if (l == r)
    {
      for (int c = 0; c < 26; c++)
        if (cnt[len][c])
          ans[l] = c;
      break;
    }

    vector<int> candidates;
    for (int c = 0; c < 26; c++)
      if (cnt[len][c] % len)
        candidates.push_back(c);

    assert(candidates.size() == 1 || candidates.size() == 2);
    ans[l] = candidates[0];
    ans[r] = candidates.back();
  }

  return ans;
}

// find actual [0, mid)
vector<int> merge(vector<int> ans0, vector<int> ans1)
{
  int n = ans0.size();
  vector<int> ans = ans0;
  ans[n - 2] = ans1[n - 2];
  for (int l = 1, r = n - 2; l < r;)
  {
    if (ans0[r] != ans1[r])
      swap(ans0[l], ans0[r]);
    ans[l] = ans0[l];
    r--;
    if (r == l)
      break;
    if (ans1[l] != ans0[l])
      swap(ans1[l], ans1[r]);
    ans[r] = ans1[r];
    l++;
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  if (n <= 2)
  {
    auto resp0 = ask(1, 1);
    int x = resp0[0][0] - 'a';
    if (n == 1)
      answer({x});
    auto resp1 = ask(2, 2);
    int y = resp1[0][0] - 'a';
    answer({x, y});
  }

  // solve [0, mid)
  int mid = (n + 1) / 2;
  vector<int> cnt(26, 0);
  auto resp0 = ask(1, mid);
  auto resp1 = ask(1, mid - 1);

  for (auto s : resp0)
    if (s.size() == 1)
      cnt[s[0] - 'a']++;
  for (auto s : resp1)
    if (s.size() == 1)
      cnt[s[0] - 'a']--;

  // find mid - 1
  int x = -1;
  for (int c = 0; c < 26; c++)
    if (cnt[c])
      x = c;
  assert(x >= 0);

  auto ans0 = construct(mid, resp0, mid - 1, x);
  auto ans1 = construct(mid - 1, resp1, 0, ans0[0]);
  auto leftHalf = merge(ans0, ans1);

  // solve [mid, n)
  auto resp2 = ask(1, n);
  auto ans = construct(n, resp2, 0, ans0[0]);
  for (int l = 0, r = n - 1; l < r; l++, r--)
    if (ans[l] != leftHalf[l])
      swap(ans[l], ans[r]);

  answer(ans);
}
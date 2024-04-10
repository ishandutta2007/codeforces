#include <bits/stdc++.h>
using namespace std;

int n, l[300300], r[300300], cnt[300300], maxGain, ansI, ansJ;
string s;

int adjust()
{
  int x = 0, minX = 0, minId = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '(') x++;
    else
    {
      x--;
      if (x < minX)
      {
        minId = i + 1;
        minX = x;
      }
    }

  if (minId)
    rotate(s.begin(), s.begin() + minId, s.end());
  return minId;
}

int isGood()
{
  int x = 0;
  for (char c : s)
    if (c == '(') x++;
    else x--;
  return !x;
}

void init()
{
  vector<int> st;
  for (int i = 0; i < n; i++)
    if (s[i] == '(') st.push_back(i);
    else
    {
      int j = st.back();
      st.pop_back();
      l[i] = j;
      r[j] = i;
    }
}

void solve(int from, int to, int depth)
{
  if (from + 1 == to)
    return;

  for (int i = to - 1; i > from; i = l[i] - 1)
  {
    solve(l[i], i, depth + 1);
    cnt[to]++;
    if (!depth && cnt[i] + 1 > maxGain)
    {
      maxGain = cnt[i] + 1;
      ansI = l[i];
      ansJ = i;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  if (!isGood())
  {
    cout << 0 << endl << 1 << ' ' << 1 << endl;
    return 0;
  }

  int minId = adjust();
  init();

  int num = 0;
  for (int i = 0; i < n; i = r[i] + 1)
  {
    solve(i, r[i], 0);
    num++;
  }

  for (int i = 0; i < n; i = r[i] + 1)
  {
    int gain = cnt[r[i]] + 1 - num;
    if (gain > maxGain)
    {
      maxGain = gain;
      ansI = i;
      ansJ = r[i];
    }
  }

  swap(s[ansI], s[ansJ]);
  ansI = (ansI + minId) % n;
  ansJ = (ansJ + minId) % n;
  adjust();
  cout << num + maxGain << endl << ansI + 1 << ' ' << ansJ + 1 << endl;
}
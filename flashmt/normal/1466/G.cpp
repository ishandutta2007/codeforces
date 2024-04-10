#include <bits/stdc++.h>
using namespace std;
const int MAX_LENGTH = 2000000;
const int BASE = 1e9 + 7;

int n, q, bound, pre[1000100];
long long p2[100100], invP2[100100],  sumCoef[26][100100];
vector<string> songs;

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y / 2);
  res = res * res % BASE;
  if (y % 2)
    res = res * x % BASE;
  return res;
}

void buildPre(string &w)
{
  pre[0] = 1;
  for (int i = 0, j = -1; i < w.size();)
  {
    while (j >= 0 && w[i] != w[j])
      j = j ? pre[j - 1] + 1 : -1;
    pre[i++] = j++;
  }
}

int countSubstr(string &s, string &t)
{
  int m = s.size(), n = t.size(), res = 0;
  for (int i = 0, j = 0; i < m;)
  {
    while (j >= 0 && s[i] != t[j])
      j = j ? pre[j - 1] + 1 : -1;
    i++;
    if (j == n - 1)
    {
      j = pre[j];
      res++;
    }
    j++;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> n >> q >> s >> t;
  songs.push_back(s);
  bound = 0;
  while (bound < n)
  {
    string newSong = songs.back();
    newSong += t[bound];
    newSong += songs.back();
    if (newSong.size() > MAX_LENGTH)
      break;
    bound++;
    songs.push_back(newSong);
  }

  for (int i = 0; i <= n; i++)
  {
    p2[i] = i ? p2[i - 1] * 2 % BASE : 1;
    invP2[i] = power(p2[i], BASE - 2);
  }

  for (int i = 0; i < 26; i++)
    for (int j = 1; j <= n; j++)
    {
      sumCoef[i][j] = sumCoef[i][j - 1];
      if (t[j - 1] - 'a' == i)
        sumCoef[i][j] = (sumCoef[i][j] + p2[n - j]) % BASE;
    }

  while (q--)
  {
    int k;
    string w;
    cin >> k >> w;
    int songId = 0;
    while (songId < k && songId < bound && songs[songId].size() < w.size())
      songId++;

    buildPre(w);
    long long ans = countSubstr(songs[songId], w) * p2[k - songId] % BASE;

    if (songId < k)
    {
      vector<int> hasLetter(26, 0);
      for (char c : w)
        hasLetter[c - 'a'] = 1;
      string suffix = songs[songId].substr(songs[songId].size() - w.size() + 1, w.size() - 1);
      string prefix = songs[songId].substr(0, w.size() - 1);
      string candidate = suffix + " " + prefix;
      for (int ch = 0; ch < 26; ch++)
        if (hasLetter[ch])
        {
          long long coef = (sumCoef[ch][k] - sumCoef[ch][songId] + BASE) % BASE * invP2[n - k] % BASE;
          candidate[w.size() - 1] = char('a' + ch);
          ans = (ans + countSubstr(candidate, w) * coef) % BASE;
        }
    }

    cout << ans << endl;
  }
}
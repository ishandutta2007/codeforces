#include <bits/stdc++.h>
using namespace std;
const string VOWELS = "aeiou";

pair <int, int> pop2(vector <int> &a)
{
  int u = a.back();
  a.pop_back();
  int v = a.back();
  a.pop_back();
  return {u, v};
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s[100100];
  cin >> n;

  vector <int> words[1000100][5];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    int vowelCnt = 0, lastId = 0;
    for (char c : s[i])
    {
      int id = find(VOWELS.begin(), VOWELS.end(), c) - VOWELS.begin();
      if (id < VOWELS.size())
      {
        vowelCnt++;
        lastId = id;
      }
    }

    words[vowelCnt][lastId].push_back(i);
  }

  vector < pair<int, int> > firstWords, secondWords;
  for (int i = 1; i <= 1e6; i++)
  {
    vector <int> remaining;
    for (int j = 0; j < VOWELS.size(); j++)
    {
      while (words[i][j].size() > 1)
        secondWords.push_back(pop2(words[i][j]));
      if (!words[i][j].empty())
        remaining.push_back(words[i][j][0]);
    }

    while (remaining.size() > 1)
      firstWords.push_back(pop2(remaining));
  }

  while (secondWords.size() > firstWords.size())
  {
    firstWords.push_back(secondWords.back());
    secondWords.pop_back();
  }

  int ans = min(firstWords.size(), secondWords.size());
  cout << ans << '\n';
  for (int i = 0; i < ans; i++)
  {
    cout << s[firstWords[i].first] << ' ' << s[secondWords[i].first] << '\n';
    cout << s[firstWords[i].second] << ' ' << s[secondWords[i].second] << '\n';
  }
}
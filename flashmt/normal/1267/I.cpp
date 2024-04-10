#include <bits/stdc++.h>
using namespace std;

int a[222][222];

int play(int x, int y)
{
  if (a[x][y] >= 0)
    return a[x][y];
  cout << "? " << x + 1 << ' ' << y + 1 << endl;
  cout.flush();
  string s;
  cin >> s;
  a[x][y] = s == ">";
  a[y][x] = s != ">";
  return a[x][y];
}

int findWorst(vector<int> candidates)
{
  if (candidates.size() == 1)
    return candidates[0];

  vector<int> losers;
  for (int i = 0; i < candidates.size(); i += 2)
    if (i == candidates.size() - 1) losers.push_back(candidates[i]);
    else if (play(candidates[i], candidates[i + 1])) losers.push_back(candidates[i + 1]);
    else losers.push_back(candidates[i]);

  return findWorst(losers);
}

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
    memset(a, -1, sizeof a);

    // play n matches to divide into 2 groups
    vector<int> winners, losers;
    for (int i = 0; i < n * 2; i += 2)
    {
      play(i, i + 1);
      winners.push_back(a[i][i + 1] ? i : i + 1);
      losers.push_back(a[i][i + 1] ? i + 1 : i);
    }
    // sort losers
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (!play(losers[i], losers[j]))
          swap(losers[i], losers[j]);

    // remove player who beat the best loser
    for (int i = 0; i < n; i++)
      if (a[winners[i]][losers[0]] == 1)
      {
        winners.erase(winners.begin() + i);
        break;
      }

    // try to put the best losers into winners
    for (int i = 0; i < n / 2; i++)
    {
      int worst = findWorst(winners);
      if (play(worst, losers[i]))
        break;

      for (int j = 0; j < winners.size(); j++)
        if (winners[j] == worst)
        {
          winners.erase(winners.begin() + j);
          break;
        }
    }

    cout << "!" << endl;
    cout.flush();
  }
}
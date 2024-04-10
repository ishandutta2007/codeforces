#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int A = 200;

int ask(int x, int y)
{
  vector<pair<int, int>> p;
  for (int i = 1; i <= A; i += x)
    for (int j = 1; j <= A; j += y)
      p.push_back({i, j});
  cout << "? " << size(p) << endl;
  for (auto [x, y] : p)
    cout << x << ' ' << y << ' ';
  cout << endl;
  cout.flush();
  int resp;
  cin >> resp;
  return resp;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int area = ask(1, 1);

  vector<int> cand;
  for (int i = 1; i < A; i++)
    if (area % (i + 1) == 0 && area / (i + 1) > 1)
      cand.push_back(i);

  for (int turn = 1; turn <= 3; turn++)
  {
    int best = oo, bestX = 0, bestY = 0;
    // debug(cand);

    for (int x = 1; x < A; x++)
      for (int y = 1; y < A; y++)
      {
        vector<pair<int, int>> choices;
        for (int w : cand)
        {
          int h = area / (w + 1) - 1;
          for (int u = (w + 1) / x; u <= (w + x) / x; u++)
            for (int v = (h + 1) / y; v <= (h + y) / y; v++)
              choices.push_back({u * v, w});
        }

        sort(begin(choices), end(choices));
        int sz = size(choices);
        int maxChoice = 0;
        for (int i = 0; i < sz;)
        {
          int j = i + 1;
          while (j < sz && choices[j].first == choices[i].first)
            j++;
          maxChoice = max(maxChoice, j - i);
          i = j;
        }

        if (maxChoice < best)
        {
          best = maxChoice;
          bestX = x;
          bestY = y;
        }
      }

    // debug(best, bestX, bestY);
    int resp = ask(bestX, bestY);
    vector<int> newCand;
    for (int w : cand)
    {
      int h = area / (w + 1) - 1, match = 0, x = bestX, y = bestY;
      for (int u = (w + 1) / x; u <= (w + x) / x; u++)
        for (int v = (h + 1) / y; v <= (h + y) / y; v++)
          if (u * v == resp)
            match = 1;

      if (match)
        newCand.push_back(w);
    }

    swap(cand, newCand);
  }

  set<int> ans;
  for (int x : cand)
    ans.insert(x + area / (x + 1) - 1);
  assert(size(ans) == 1);
  cout << "! " << *ans.begin() * 2 << endl;
  cout.flush();
}
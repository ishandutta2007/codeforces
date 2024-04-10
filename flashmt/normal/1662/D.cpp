#include <bits/stdc++.h>
using namespace std;
const vector<string> PATTERNS = {"AA", "B", "CC"};

string refine(string s)
{
  while (1)
  {
    int found = 0;
    for (auto t : PATTERNS)
    {
      int i = s.find(t);
      if (i >= 0)
      {
        s.erase(i, size(t));
        found = 1;
        break;
      }
    }
    if (!found)
      break;
  }
  return s;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    string s, t;
    cin >> s >> t;

    vector<int> cntS(3), cntT(3);
    for (char c : s)
      cntS[c - 'A']++;
    for (char c : t)
      cntT[c - 'A']++;

    int isGood = 1;
    for (int i = 0; i < 3; i++)
      if (cntS[i] % 2 != cntT[i] % 2)
        isGood = 0;

    cout << (isGood && refine(s) == refine(t) ? "YES" : "NO") << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

string homeTeam, awayTeam, team, card;
int minute, number, cnt[2][100], n;

int main()
{
  ios::sync_with_stdio(0);
  cin >> homeTeam >> awayTeam >> n;
  while (n--)
  {
    cin >> minute >> team >> number >> card;
    if (cnt[team == "a"][number] >= 2) continue;
    if (card == "r")
    {
      cnt[team == "a"][number] += 2;
      cout << (team == "a" ? awayTeam : homeTeam) << ' ' << number << ' ' << minute << endl;
    }
    else
      if (++cnt[team == "a"][number] == 2)
        cout << (team == "a" ? awayTeam : homeTeam) << ' ' << number << ' ' << minute << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, maxHp, regen, pow[1111], dmg[1111], used[1111] = {0};
  cin >> n >> maxHp >> regen;
  for (int i = 0; i < n; i++)
    cin >> pow[i] >> dmg[i];

  int hp = maxHp, t = 0, sumDmg = 0;
  vector<pair<int, int>> scrolls;
  while (1)
  {
    hp = min(maxHp, hp - sumDmg + regen);
    if (hp <= 0)
      break;

    int id = -1, maxDmg = 0;
    for (int i = 0; i < n; i++)
      if (!used[i] && hp * 100 <= maxHp * pow[i] && dmg[i] > maxDmg)
      {
        maxDmg = dmg[i];
        id = i;
      }

    if (id < 0 && sumDmg <= regen)
      break;

    if (id >= 0)
    {
      scrolls.push_back({t, id});
      used[id] = 1;
      sumDmg += dmg[id];
    }
    t++;
  }

  if (hp > 0) cout << "NO" << endl;
  else
  {
    cout << "YES" << endl << t << ' ' << scrolls.size() << endl;
    for (auto [t, id] : scrolls)
      cout << t << ' ' << id + 1 << endl;
  }
}
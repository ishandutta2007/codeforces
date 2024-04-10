#include <bits/stdc++.h>
using namespace std;

long long getDamage(long long cast, long long damage, long long regen, long long cooldown)
{
  return (cast + 1) * damage - cast * (cast + 1) / 2 * cooldown * regen;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    long long damage, regen, duration, cooldown;
    cin >> damage >> regen >> duration >> cooldown;
    if (damage > regen * duration) cout << "-1\n";
    else if (cooldown >= duration) cout << damage << '\n';
    else
    {
      int low = 0, high = (duration - 1) / cooldown;
      while (high - low >= 6)
      {
        long long mid1 = (low * 2 + high) / 3, damage1 = getDamage(mid1, damage, regen, cooldown);
        long long mid2 = (low + high * 2) / 3, damage2 = getDamage(mid2, damage, regen, cooldown);
        if (damage1 < damage2) low = mid1;
        else high = mid2;
      }

      long long ans = damage;
      for (int i = low; i <= high; i++)
        ans = max(ans, getDamage(i, damage, regen, cooldown));

      cout << ans << '\n';
    }
  }
}
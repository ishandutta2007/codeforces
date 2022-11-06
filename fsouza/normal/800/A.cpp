#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const double E = 1e-8;

int main() {
  int n, charger_speed;
  scanf("%d %d", &n, &charger_speed);
  vector<int> draws(n), contains(n);
  lint draw_sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &draws[i], &contains[i]);
    draw_sum += draws[i];
  }
  if (charger_speed >= draw_sum) {
    printf("-1\n");
  } else {
    vector<pair<double, int>> die_at(n);
    for (int i = 0; i < n; ++i)
      die_at[i] = make_pair((double)contains[i] / draws[i], i);
    sort(die_at.begin(), die_at.end());
    double energy_used = 0;
    int bottleneck_until = 0;
    double bottleneck_draw = draws[die_at[0].second];
    for (int i = 0; i + 1 < n; ++i) {
      double extra_energy =
          (die_at[i + 1].first - die_at[i].first) * bottleneck_draw;
      if (energy_used + extra_energy <= die_at[i + 1].first * charger_speed + E) {
        energy_used += extra_energy;
        bottleneck_until = i + 1;
        bottleneck_draw += draws[die_at[i + 1].second];
      } else {
        break;
      }
    }
    double power_off =
        (die_at[bottleneck_until].first * bottleneck_draw - energy_used) /
        (bottleneck_draw - charger_speed);
    printf("%.10f\n", power_off);
  }
  return 0;
}
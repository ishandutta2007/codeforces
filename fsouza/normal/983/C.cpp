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

const int nfloor = 9, capacity = 4;

typedef tuple<int, set<int>> state_t;

struct person_t {
  int from, to;
};
int n;
vector<person_t> people;

map<state_t, vector<int>> memo;

state_t advance_state(const state_t &state, int floor) {
  int nentered;
  set<int> in_elevator;
  tie(nentered, in_elevator) = state;
  for (auto it = in_elevator.begin(); it != in_elevator.end();) {
    if (people[*it].to == floor) in_elevator.erase(it++);
    else ++it;
  }
  while (nentered < n && people[nentered].from == floor &&
         in_elevator.size() < capacity) {
    in_elevator.insert(nentered++);
  }
  return {nentered, in_elevator};
}

int solve(int nentered, set<int> in_elevator, int query_floor) {
  if (nentered == n && in_elevator.empty())
    return 0;
  state_t state{nentered, in_elevator};
  auto emplace_result = memo.emplace(state, vector<int>{});
  if (emplace_result.second == false) {
    assert(!emplace_result.first->second.empty());
    return emplace_result.first->second[query_floor];
  }

  vector<int> &result = emplace_result.first->second;
  result.resize(nfloor, INT_MAX / 2);
  for (int floor = 0; floor < nfloor; ++floor) {
    state_t state2 = advance_state(state, floor);
    if (state2 != state)
      result[floor] = solve(get<0>(state2), get<1>(state2), floor);
  }
  for (int floor = 1; floor < nfloor; ++floor)
    result[floor] = min(result[floor], 1 + result[floor - 1]);
  for (int floor = nfloor - 2; floor >= 0; --floor)
    result[floor] = min(result[floor], 1 + result[floor + 1]);

  return result[query_floor];
}

int main() {
  scanf("%d", &n);
  people.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &people[i].from, &people[i].to);
    --people[i].from, --people[i].to;
  }
  printf("%d\n", 2 * n + solve(0, {}, 0));
  return 0;
}
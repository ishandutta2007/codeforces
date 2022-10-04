#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  set <int> fr, lg;
  ll sum = 0; 
  set <int> bad, good;
  ll sum_good = 0;
  auto balance = [&] () {
    int k = lg.size();
    while (good.size() > k) {
      int x = *good.begin();
      sum_good -= x;
      good.erase(x);
      bad.insert(x);
    }
    while (good.size() < k) {
      int x = *bad.rbegin();
      sum_good += x;
      bad.erase(x);
      good.insert(x);
    }
  };
  auto get_double = [&] () {
    if (good.empty() || (!fr.empty() && (*fr.rbegin() >= (*good.begin())))) {
      return sum_good;
    } else {
      ll cur_sum = sum_good;
      cur_sum -= (*lg.begin());
      if (!fr.empty()) cur_sum += (*fr.rbegin());
      return cur_sum;
    }
  };
  auto del = [&] (int tp, int x) {
    if (tp == 0) {
      fr.erase(x);
    } else {
      lg.erase(x);
    }
    if (bad.count(x)) {
      bad.erase(x);
    } else {
      good.erase(x);
      sum_good -= x;
    }
    sum -= x;
    balance();
  };  
  auto add = [&] (int tp, int x) {
    if (tp == 0) {
      fr.insert(x);
    } else {
      lg.insert(x);
    }
    if (good.empty() || (*good.begin() > x)) {
      bad.insert(x);
    } else {
      good.insert(x);
      sum_good += x;
    }
    sum += x;
    balance();
  };
  while (n--) {
    int tp, x;
    cin >> tp >> x;
    if (x < 0) {
      del(tp, -x);
    } else {
      add(tp, x);
    }
    cout << sum + get_double() << '\n';
  }
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    vector<char> letter;
    vector<int> cnt(26, 0);
    for (char c : s) {
      letter.emplace_back(c);
      ++cnt[c - 'a'];
    }
    sort(ALL(letter));
    letter.erase(unique(ALL(letter)), letter.end());
    if (letter.size() == 2 || letter.size() == 3) {
      bool no_answer = true;
      FOR(i, 1, letter.size()) {
        if (abs(letter[i] - letter[i - 1]) > 1) no_answer = false;
      }
      if (no_answer) {
        cout << "No answer\n";
      } else {
        string ans = "";
        if (letter.size() == 2) {
          REP(i, cnt[letter[0] - 'a']) ans += letter[0];
          REP(i, cnt[letter[1] - 'a']) ans += letter[1];
        } else if (abs(letter[1] - letter[0]) > 1) {
          REP(i, cnt[letter[1] - 'a']) ans += letter[1];
          REP(i, cnt[letter[0] - 'a']) ans += letter[0];
          REP(i, cnt[letter[2] - 'a']) ans += letter[2];
        } else {
          REP(i, cnt[letter[1] - 'a']) ans += letter[1];
          REP(i, cnt[letter[2] - 'a']) ans += letter[2];
          REP(i, cnt[letter[0] - 'a']) ans += letter[0];
        }
        cout << ans << '\n';
      }
      continue;
    }
    string ans = "";
    int idx = letter.size() / 2;
    REP(i, cnt[letter[idx] - 'a']) ans += letter[idx];
    int left = 0, right = letter.size() - 1;
    while (true) {
      if (left == idx) break;
      REP(i, cnt[letter[left] - 'a']) ans += letter[left];
      ++left;
      if (right == idx) break;
      REP(i, cnt[letter[right] - 'a']) ans += letter[right];
      --right;
    }
    cout << ans << '\n';
  }
  return 0;
}
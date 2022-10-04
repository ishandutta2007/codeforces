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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

struct Node {
  vector <pair <int, string>> go;
  Node() {
    go.resize(2);
    go[0] = {0, "$"};
    go[1] = {1, "$"};
  }
  Node(string s) {
    go.resize(2);
    go[0] = {0, "$"};
    go[1] = {1, "$"};
    if (s == "lock") {
      go[0].first = go[1].first = 1;
    } else if (s == "unlock") {
      go[0].first = go[1].first = 0;
    } else {
      go[0].second = s;
    }
  }
  Node operator +(const Node &other) {
    Node ret = Node();
    ret.go[0].first = other.go[go[0].first].first;
    ret.go[0].second = go[0].second;
    if (other.go[go[0].first].second != "$") {
      ret.go[0].second = other.go[go[0].first].second;
    }
    ret.go[1].first = other.go[go[1].first].first;
    ret.go[1].second = go[1].second;
    if (other.go[go[1].first].second != "$") {
      ret.go[1].second = other.go[go[1].first].second;
    }
    return ret;
  }
};  

const int N = 1e5 + 7;

Node t[4 * N];

void modify(int id, string s, int l, int r, int v) {
  if (l == r) {
    t[v] = Node(s);
  } else {
    int m = (l + r) >> 1;
    if (id <= m) modify(id, s, l, m, 2 * v + 1);
    else modify(id, s, m + 1, r, 2 * v + 2);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    modify(i, s, 0, n - 1, 0);
  }
  auto print_ans = [&] () {
    string res = t[0].go[0].second;
    if (res == "$") cout << "blue\n";
    else cout << res << '\n';
  };
  print_ans();
  int q;
  cin >> q;
  while (q--) {
    int id; string s;
    cin >> id >> s;
    --id;
    modify(id, s, 0, n - 1, 0);
    print_ans();
  }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 gen(time(0));

struct vec {
  ll x, y;
  void read() {
    cin >> x >> y;
  }
  vec operator-(vec p) {
    return {x - p.x, y - p.y};
  }
  ll operator%(vec p) {
    return x * p.y - y * p.x;
  }
  bool operator==(vec p) {
    return (x == p.x && y == p.y);
  }
};

bool solveone(vector <vec> &p) {
  if ((int)p.size() < 3)
    return true;
  for (int i = 2; i < (int)p.size(); i++)
    if ((p[i] - p[1]) % (p[i] - p[0]))
      return false;
  return true;
}

bool solvetwo(vector <vec> &p) {
  if (p.size() < 5)
    return true;
  int n = (int)p.size();
  vec a = p[gen() % n];
  vec b = p[gen() % n];
  while (a == b) {
    a = p[gen() % n];
    b = p[gen() % n];
  }
  vector <vec> c;
  for (int i = 0; i < n; i++)
    if ((p[i] - a) % (p[i] - b))
      c.push_back(p[i]);
  return solveone(c);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <vec> p(n);
  for (int i = 0; i < n; i++)
    p[i].read();
  int cnt = 0;
  while (clock() / CLOCKS_PER_SEC < 1.8) {
    cnt++;
    if (solvetwo(p)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
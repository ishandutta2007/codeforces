// October 10, 2020
// https://codeforces.com/contest/1427/problem/E

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427E.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427E.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


long long gcd(long long x, long long y) {
  while (y != 0) {
    x %= y;
    swap(x, y);
  }
  return x;
}

void Diophantine(long long x, long long y, long long& a, long long& b) {
  if (y == 0) {
    assert(x == 1);
    a = 1;
    b = 0;
    return;
  }
  int r = x / y;
  long long c, d;
  Diophantine(y, x - r * y, c, d);
  a = d;
  b = c - d * r;
}

void Test() {
  for (long long x = 3; x <= 999999; x += 2) {
    int shift = 0;
    while (gcd(x, ((x << shift) ^ x)) > 1) {
      shift += 1;
    }
    vector<string> ops;
    const long long MAX = (long long) 5e18;
    set<long long> on_board;
    on_board.insert(x);
    auto Do = [&](char op, long long x, long long y) {
      assert(0 <= x && x <= MAX && 0 <= y && y <= MAX);
      // ops.push_back(to_string(x) + ' ' + op + ' ' + to_string(y));
      assert(on_board.count(x) && on_board.count(y));
      if (op == '+') {
        on_board.insert(x + y);
      } else {
        on_board.insert(x ^ y);
      }
    };
    for (int i = 0; i < shift; i++) {
      long long t = (x << i);
      Do('+', t, t);
    }
    Do('^', x, (x << shift));
    long long y = (x << shift) ^ x;

    long long a, b;
    // cin >> a >> b;
    Diophantine(x, y, a, b);
    // cerr << a << " * " << x << " + " << b << " * " << y << " = 1\n";
    a = abs(a);
    b = abs(b);

    Do('^', x, x);
    for (int rot = 0; rot < 2; rot++) {
      long long t = x;
      while (t + t <= x * a) {
        Do('+', t, t);
        t += t;
      }
      long long cur = 0;
      for (int j = 0; (1LL << j) <= a; j++) {
        if (a & (1LL << j)) {
          Do('+', cur, (x << j));
          cur += (x << j);
        }
      }
      swap(x, y);
      swap(a, b);
    }

    long long n = x * a, m = y * b;
    if (n > m) {
      swap(n, m);
    }
    if (n % 2 == 1) {
      Do('+', n, x);
      Do('+', m, x);
      n += x;
      m += x;
    }
    Do('^', n, m);
    assert(on_board.count(1));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  // Test();

  long long x;
  cin >> x;
  int shift = 0;
  while (gcd(x, ((x << shift) ^ x)) > 1) {
    shift += 1;
  }
  vector<string> ops;
  const long long MAX = (long long) 5e18;
  auto Do = [&](char op, long long x, long long y) {
    assert(0 <= x && x <= MAX && 0 <= y && y <= MAX);
    ops.push_back(to_string(x) + ' ' + op + ' ' + to_string(y));
  };
  for (int i = 0; i < shift; i++) {
    long long t = (x << i);
    Do('+', t, t);
  }
  Do('^', x, (x << shift));
  long long y = (x << shift) ^ x;

  long long a, b;
  // cin >> a >> b;
  Diophantine(x, y, a, b);
  // cerr << a << " * " << x << " + " << b << " * " << y << " = 1\n";
  a = abs(a);
  b = abs(b);

  Do('^', x, x);
  for (int rot = 0; rot < 2; rot++) {
    long long t = x;
    while (t + t <= x * a) {
      Do('+', t, t);
      t += t;
    }
    long long cur = 0;
    for (int j = 0; (1LL << j) <= a; j++) {
      if (a & (1LL << j)) {
        Do('+', cur, (x << j));
        cur += (x << j);
      }
    }
    swap(x, y);
    swap(a, b);
  }

  long long n = x * a, m = y * b;
  if (n > m) {
    swap(n, m);
  }
  if (n % 2 == 1) {
    Do('+', n, x);
    Do('+', m, x);
    n += x;
    m += x;
  }
  Do('^', n, m);

  cout << ops.size() << '\n';
  for (auto& s : ops) {
    cout << s << '\n';
  }


  return 0;
}
#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

int main(void) 
{
  string z = "CODEFORCES";
  string s; cin >> s;

  if (s.size() < z.size()) {
    puts("NO");
    exit(0);
  }

  if (s.substr(0, z.size()) == z) {
    puts("YES");
    exit(0);
  }

  if (s.substr(s.size() - z.size(), z.size()) == z) {
    puts("YES");
    exit(0);
  }

  int n = s.size();
  REP(i, n) FOR(j, i + 1, n) {
    string pref = s.substr(0, i + 1);
    string suff = s.substr(j, n - j);
    if (pref + suff == z) {
      puts("YES");
      exit(0);
    }
  }

  puts("NO");

  return 0;
}
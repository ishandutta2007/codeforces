#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MOD = 1000000007;

int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return (llint)a * b % MOD; }

#define MAX 100005

int n;
char buf[MAX];
string s;
vector< char > d;
vector< string > q;

typedef pair< llint, llint > num;
num operator+(const num &a, const num &b) {
  return num(mul(a.first, b.first), add(mul(a.second, b.first), b.second));
}

num dig[10];

num solve(string &s) {
  int n = s.size();

  num ret = {1, 0};
  for (int i = 0; i < n; ++i) 
    ret = ret + dig[s[i] - '0'];

  return ret;
}

int main(void)
{
  cin >> s;
  cin >> n;

  REP(i, n) {
    scanf("%s", buf);
    d.push_back(buf[0]);
    q.push_back(string(buf + 3));
  }

  REP(i, 10) dig[i] = {10, i};

  for (int i = n - 1; i >= 0; --i) 
    dig[d[i] - '0'] = solve(q[i]);

  cout << solve(s).second << endl;

  return 0;
}
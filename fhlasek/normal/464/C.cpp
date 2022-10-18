/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MOD 1000000007

int power(int base, long long exponent) {
  int result = 1, m = base;
  while(exponent) {
    if(exponent&1) result = ((long long)result*m) % MOD;
    m = ((long long)m*m) % MOD;
    exponent /= 2;
  }
  return result;
}

#define MAXN 222222
char input[MAXN];
char rule[MAXN];

vector<pair<int, string> > rules;

int val[10], digits[10];

int main(int argc, char *argv[]) {
  REP(i, 10) { val[i] = i; digits[i] = 1; }
  scanf("%s", input);
  int R;
  scanf("%d", &R);
  REP(i, R) {
    scanf("%s", rule);
    rules.push_back(make_pair(rule[0] - '0', string(rule + 3)));
  }
  FORD(i, R - 1, 0) {
    int new_val = 0, new_digits = 0;
    REP(j, rules[i].second.size()) {
      int d = rules[i].second[j] - '0';
      new_val = ((long long)new_val * power(10, digits[d]) + val[d]) % MOD;
      new_digits = (new_digits + digits[d]) % (MOD - 1);
    }
    val[rules[i].first] = new_val;
    digits[rules[i].first] = new_digits;
  }
  int ans = 0, N = strlen(input);
  REP(i, N) ans = ((long long)ans * power(10, digits[input[i] - '0']) + val[input[i] - '0']) % MOD;
  printf("%d\n", ans);
  return 0;
}
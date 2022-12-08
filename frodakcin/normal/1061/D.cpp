#include <iostream>
#include <cstdio>

#include <stack>
#include <queue>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 100;

const int MOD = 1e9 + 7;
typedef long long ll;
#define tll(x) static_cast<ll>(x)
#define ti(x) static_cast<int>(x)

int sum(int a, int b) {return ti((tll(a) + tll(b))%MOD);}
int prod(int a, int b) {return ti((tll(a) * tll(b))%MOD);}

typedef pair<int, int> pii;
#define mp make_pair
#define ff first
#define ss second

typedef stack<int> si;
typedef priority_queue<int, vector<int>, greater<int> > qi;

int N, x, y;
pii show[MAXN];
qi run;
si opn;

int main() {
  scanf("%d%d%d", &N, &x, &y);
  x -= y;
  for(int i = 0, a, b;i < N;i++) {
    scanf("%d%d", &a, &b);
    show[i] = mp(a, ++b);
  }
  sort(show, show + N);
  
  int ans = 0;
  for(int i = 0;i < N;i++) {
    while(!run.empty() and not (show[i].ff < run.top())) opn.push(run.top()), run.pop();
    if(!opn.empty() and tll(y) * (show[i].ff - opn.top()) < x) {
      ans = sum(ans, prod(y, show[i].ss - opn.top()));
      run.push(show[i].ss);
      opn.pop();
    } else {
      ans = sum(ans, sum(x, prod(y, show[i].ss - show[i].ff)));
      run.push(show[i].ss);
    }
  }
  
  printf("%d\n", ans);
  
  return 0;
}
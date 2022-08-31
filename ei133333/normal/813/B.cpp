#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 X, Y, L, R;
  cin >> X >> Y >> L >> R;

  vector< int64 > latte, malta;
  int64 beet = 1;
  for(;;) {
    latte.push_back(beet);
    if((double) beet * X > R) break;
    beet *= X;
  }
  beet = 1;
  for(;;) {
    malta.push_back(beet);
    if((double) beet * Y > R) break;
    beet *= Y;
  }

  set< int64 > st;
  st.emplace(L - 1);
  st.emplace(R + 1);
  for(auto &a : latte) {
    for(auto &b : malta) st.emplace(a + b);
  }

  auto s = st.lower_bound(L - 1);
  int64 ret = 0LL;
  while(*s != R + 1) {
    int64 now = *s + 1;
    ret = max(ret, *++s - now);
  }
  cout << ret << endl;
}
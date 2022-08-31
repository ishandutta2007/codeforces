#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

map< int64, int64 > sz;

int64 calc(int64 x)
{
  if(sz.count(x)) return(sz[x]);
  if(x <= 1) return(1);
  return(sz[x] = calc(x / 2) + 1 + calc(x / 2));
}

int main()
{
  int64 n, l, r;
  cin >> n >> l >> r;

  int ret = 0;
  for(int64 i = l; i <= r; i++) {
    int64 now = n;
    int64 pos = i;
    while(now >= 2) {
      int64 sz = calc(now/2);
      if(pos <= sz) now /= 2;
      else if(pos == sz + 1) now = now % 2;
      else now /= 2, pos -= sz + 1;
    }
    ret += now;
  }

  cout << ret << endl;
}
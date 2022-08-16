#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  bool X[1000001] = {};
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    X[x] = true;
  }

  vector< int > ans;
  int ret = 0;
  int sz = 1000000;
  for(int i = 1; i <= sz; i++) {
    if(X[i] && X[sz + 1 - i]) ++ret;
  }
  for(int i = 0; i <= sz; i++) {
    if(X[i] && !X[sz + 1 - i]) {
      X[sz + 1 - i] = true;
      ans.push_back(sz + 1 - i);
    }
  }
  ret /= 2;
  for(int i = 1; i <= sz; i++) {
    if(!X[i] && !X[sz + 1 - i] && ret > 0) {
      X[i] = true;
      X[sz + 1 - i] = true;
      ans.push_back(i);
      ans.push_back(sz + 1 - i);
      --ret;
    }
  }

  sort(begin(ans), end(ans));
  printf("%d\n", (int) ans.size());
  for(int i = 0; i < N; i++) {
    printf("%d ", ans[i]);
  }
  puts("");
}
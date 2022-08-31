#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, s[300000] = {};

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n);

  int R = max(-1, (n - k) * 2 - 1);
  int ret = 0;
  if(R + 1 != n) ret = *max_element(&s[R + 1], &s[n]);
  int L = 0;
  while(L < R) {
    ret = max(ret, s[R--] + s[L++]);
  }
  cout << ret << endl;
}
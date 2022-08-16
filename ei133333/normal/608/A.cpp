#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, s;
  cin >> n >> s;
  int ret = s;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ret = max(ret, b + a);
  }
  cout << ret << endl;
}
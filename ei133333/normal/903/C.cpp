#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;

  cin >> N;
  map< int, int > cc;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    cc[a]++;
  }
  int ret = 0;
  for(auto& p : cc) ret = max(ret, p.second);
  cout << ret << endl;
}
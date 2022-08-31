#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector< int > a(N);
  for(int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  int ret = 0;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      swap(a[i], a[j]);
      int p = max_element(begin(a), end(a)) - begin(a);
      int q = min_element(begin(a), end(a)) - begin(a);
      ret = max(ret, abs(p - q));
      swap(a[i], a[j]);
    }
  }
  cout << ret << endl;
}
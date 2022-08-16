#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;

  cin >> N;
  int all = 0;
  while(N--) {
    int K;
    cin >> K;
    all += K;
  }
  cin >> M;
  for(int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    if(all <= r) {
      cout << max(all, l) << endl;
      return(0);
    }
  }
  cout << -1 << endl;
}
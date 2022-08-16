#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int N, A[200000];
  int beet[200000];
  fill_n(beet, 200000, INF);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  int st = -1;
  for(int i = 0; i < N; i++) {
    if(A[i] == 0) st = i;
    if(~st) beet[i] = min(beet[i], i - st);
  }
  st = -1;
  for(int i = N - 1; i >= 0; i--) {
    if(A[i] == 0) st = i;
    if(~st) beet[i] = min(beet[i], st - i);
  }
  for(int i = 0; i < N; i++) {
    cout << beet[i] << " ";
  }
  cout << endl;
}
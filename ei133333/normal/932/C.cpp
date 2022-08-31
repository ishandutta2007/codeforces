#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 N, A, B;
  cin >> N >> A >> B;

  for(int64 x = 0; A * x <= N; x++) {
    int64 rest = N - A * x;
    if(rest % B == 0) {
      int64 y = rest / B;

      vector< int64 > ret(N);
      iota(begin(ret), end(ret), 1LL);

      for(int i = 0; i < x; i++) {
        int64 left = i * A;
        int64 right = (i + 1) * A;

        int64 last = ret[left];
        for(int j = 0; j < A - 1; j++) {
          ret[left + j] = ret[left + j + 1];
        }
        ret[left + A - 1] = last;
      }



      for(int i = 0; i < y; i++) {
        int64 left = A * x + i * B;
        int64 right = A * x + (i + 1) * B;

        int64 last = ret[left];
        for(int j = 0; j < B - 1; j++) {
          ret[left + j] = ret[left + j + 1];
        }
        ret[left + B - 1] = last;
      }




      for(int i = 0; i < N; i++) {
        cout << ret[i] << " ";
      }
      cout << endl;
      return (0);
    }
  }

  cout << -1 << endl;
}
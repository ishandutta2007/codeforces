#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;

int N, A[5000];
int64 sum[5001];
int beet[5001];


int main()
{
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    sum[i + 1] = A[i] + sum[i];
  }

  int myon = N;
  for(int i = N; i >= 0; i--) {
    if(sum[i] > sum[myon]) myon = i;
    beet[i] = myon;
  }

  int64 ret = -INF;
  int a, b, c;

  for(int delim0 = 0; delim0 <= N; delim0++) {
    for(int delim1 = delim0; delim1 <= N; delim1++) {
      const int64 res = sum[delim0] - sum[delim1] + sum[beet[delim1]];
      if(ret < res) {
        ret = res;
        a = delim0, b = delim1, c = beet[delim1];
      }


      /*
      res += sum[delim0];
      res -= sum[delim1] - sum[delim0];
      res += sum[delim2] - sum[delim1];
      res -= sum[N] - sum[delim2];

      res = sum[delim0] - sum[delim1] + sum[delim0] + sum[delim2] - sum[delim1] - sum[N] + sum[delim2];
      res = sum[delim0] - sum[delim1] + sum[delim2]; // maximum
       */

    }
  }

  cout << a << " " << b << " " << c << endl;
}
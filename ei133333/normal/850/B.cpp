#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 60;
const int LIM = 2000000;

int64 N, X, Y, A[LIM + 1], B[LIM + 1];

int main()
{
  scanf("%lld %lld %lld", &N, &X, &Y);
  for(int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    A[x] += x;
    B[x] += 1;
  }
  for(int i = 1; i <= LIM; i++) {
    A[i] += A[i - 1];
    B[i] += B[i - 1];
  }

  // count of add
  int64 rest = X / Y;


  vector< int > prime(LIM + 1, true), primes;
  int64 ret = X * N;
  for(int i = 2; i < prime.size(); i++) {
    if(prime[i]) {

      vector< int64 > dump;
      dump.push_back(0);
      dump.push_back(i);
      for(int j = i + i; j < prime.size(); j += i) {
        prime[j] = false;
        dump.push_back(j);
      }


      int64 beet = 0;
      for(int j = 1; j < dump.size(); j++) {
        const int64 low = dump[j - 1] + 1; // [low, mid)
        const int64 mid = max(dump[j] - rest, dump[j - 1] + 1); // [mid, high)
        const int64 high = dump[j];

        const int64 dump1 = B[mid - 1] - B[low - 1];
        const int64 dump2 = B[high - 1] - B[mid - 1];
        const int64 dump3 = A[high - 1] - A[mid - 1];
        beet += dump1 * X;
        beet += (dump2 * dump[j] - dump3) * Y;
      }
      ret = min(ret, beet);
    }
  }

  cout << ret << endl;
}
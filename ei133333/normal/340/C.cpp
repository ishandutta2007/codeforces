#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 N, a[100000], sum[100001];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  sort(a, a + N);
  
  sum[0] = 0;
  for(int i = 0; i < N; i++) {
    sum[i + 1] = sum[i] + a[i];
  }

  int64 all = sum[N];
  for(int i = 0; i < N; i++) {
    all += (sum[N] - sum[i]) - (N - i) * a[i];
    all += i * a[i] - sum[i];
  }
  int64 gcd = __gcd(all, N);

  cout << all / gcd << " " << N / gcd << endl;
}
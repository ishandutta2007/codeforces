#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 N, P, L[100001], R[100001];

int main()
{
  // P 
  // 

  cin >> N >> P;
  long double ret = 0;
  for(int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
  }
  L[N] = L[0];
  R[N] = R[0];

  for(int i = 0; i < N; i++) {
    int64 cur = R[i] / P - (L[i] - 1) / P; 
    int64 nxt = R[i + 1] / P - (L[i + 1] - 1) / P;
    int64 curdist = R[i] - L[i] + 1;
    int64 nxtdist = R[i + 1] - L[i + 1] + 1;
    int64 sum = cur * nxtdist + nxt * curdist - nxt * cur;
    int64 all = curdist * nxtdist;
    ret += 2000.0 / all * sum;
  }
  cout << fixed << setprecision(20) << ret << endl;
}
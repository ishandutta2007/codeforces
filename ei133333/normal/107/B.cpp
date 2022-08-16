#include <bits/stdc++.h>

using namespace std;

double comb(int n, int r)
{
  double ret = 1.0;
  for(int i = 1; i < r; i++) n *= i;

}

int main()
{
  int N, M, H, S[1000];

  cin >> N >> M >> H;

  --H;
  --N;
  int all = -1;

  for(int i = 0; i < M; i++) {
    cin >> S[i];
    all += S[i];
  }

  if(all < N) {
    cout << -1 << endl;
    return(0);
  }

  int beet = all - (S[H] - 1);
  double ret = 1.0;
  for(int i = 0; i < N; i++) {
    ret *= beet * 1.0 / (all * 1.0);
    --beet;
    --all;
  }

  cout << fixed << setprecision(10) << 1.0 - ret << endl;
}
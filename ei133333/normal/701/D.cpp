#include<bits/stdc++.h>
using namespace std;


int N, L, V1, V2, K;
int kaisu;

double check(double alpha)
{
  double x = 0, y = 0;
  for(int i = 0; i < kaisu; i++) {
    x = (-V2 * x + y - alpha) / (V1 - V2);
    y = V1 * x + alpha;
    if(i + 1 != kaisu) {
      x = (V2 * x + y) / (V1 + V2);
      y = V1 * x;
    }
  }
  if(y > L) return(1e18);
  return(x);
}

int main()
{
  cin >> N >> L >> V1 >> V2 >> K;
  kaisu = (N + K - 1) / K;
  double low = 0, high = 1e18;
  for(int i = 0; i < 400; i++) {
    double left = (low * 2 + high) / 3;
    double right = (low + high * 2) / 3;
    if(check(left) < check(right)) low = left;
    else high = right;
  }
  cout << fixed << setprecision(10) << check(low) << endl;
}
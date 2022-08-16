#include<bits/stdc++.h>

using namespace std;


int main()
{
  cout << fixed << setprecision(12);

  int N, R;
  cin >> N >> R;
  double X[1000], Y[1000];

  for(int i = 0; i < N; i++) {
    cin >> X[i];

    double latte = X[i] - R;
    double malta = X[i] + R;
    Y[i] = R;

    for(int j = 0; j < i; j++) {
      double A = X[j] - R;
      double B = X[j] + R;
      if(latte > B || malta < A) continue;
      auto tail = abs(X[i] - X[j]);
      auto ffff = 2 * R;
      Y[i] = max(Y[i], Y[j] + sqrt(ffff * ffff - tail * tail));
    }

    cout << Y[i] << " ";
  }
  cout << endl;
}
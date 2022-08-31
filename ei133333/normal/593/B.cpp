#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

typedef pair< int64, int64 > Pi;

int main()
{
  int N;
  cin >> N;
  int64 x1, x2;
  cin >> x1 >> x2;
  vector< Pi > data(N);
  for(int i = 0; i < N; i++) {
    int k, b;
    cin >> k >> b;
    data[i] = Pi(k * x1 + b, k * x2 + b);
  }
  sort(data.begin(), data.end());
  for(int i = 1; i < N; i++) {
    if(data[i].second < data[i - 1].second) {
      cout << "Yes" << endl;
      exit(0);
    }
  }
  cout << "No" << endl;
}
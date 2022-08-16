#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, H[100000];
  vector< int > data;

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> H[i];
    data.push_back(H[i]);
  }
  sort(data.begin(), data.end());
  map< int, int > C;
  for(int i = 0; i < N; i++) {
    H[i] = lower_bound(data.begin(), data.end(), H[i]) - data.begin();
    H[i] += C[H[i]]++;
  }
  int Que = H[0];
  int ret = 1;
  for(int i = 1; i < N; i++) {
    if(Que < i) {
      Que = 0;
      ++ret;
    }
    Que = max(Que, H[i]);
  }
  cout << ret << endl;
}
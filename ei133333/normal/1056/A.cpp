#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  int times[101] = {};
  for(int i = 0; i < N; i++) {
    int k;
    cin >> k;
    while(k--) {
      int x;
      cin >> x;
      times[x]++;
    }
  }
  for(int i = 1; i <= 100; i++) {
    if(times[i] == N) {
      cout << i << " ";
    }
  }
  cout << endl;

}
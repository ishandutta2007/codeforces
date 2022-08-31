#include <bits/stdc++.h>
using namespace std;

int mas[500][500], mas2[500][500];
int N, K;
int main()
{
  cin >> N >> K;
  --K;

  int ptr = N * N;
  for(int i = 0; i < N; i++) {
    for(int j = N - 1; j >= K; j--) {
      mas[i][j] = ptr--; 
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = K - 1; j >= 0; j--) {
      mas[i][j] = ptr--;
    }
  }

  long long sum = 0;
  for(int i = 0; i < N; i++) {
    sum += mas[i][K];
  }
  cout << sum << endl;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(j > 0) cout << " ";
      cout << mas[i][j];
    }
    cout << endl;
  }
}
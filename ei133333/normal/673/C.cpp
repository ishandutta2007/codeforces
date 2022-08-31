#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, T[5000];
  int sum[5000] = {};
  
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> T[i];
    --T[i];
  }
  for(int i = 0; i < N; i++) {
    vector< int > colors(N, 0);
    int each = 0;
    for(int j = i; j < N; j++) {
      colors[T[j]]++;
      if(colors[each] < colors[T[j]] ||
         (colors[each] == colors[T[j]] && each > T[j])) {
        each = T[j];
      }
      ++sum[each];
    }
  }

  for(int i = 0; i < N; i++) {
    if(i > 0) cout << " ";
    cout << sum[i];
  }
  cout << endl;
}
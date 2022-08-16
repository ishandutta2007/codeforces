#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int prev = 15;
  for(int i = 0; i < N; i++) {
    int t;
    cin >> t;
    if(prev >= t) prev = t + 15;
  }
  cout << min(90, prev) << endl;
}
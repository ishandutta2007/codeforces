#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) cout << "I hate ";
    else cout << "I love ";
    if(i == N - 1) cout << "it";
    else cout << "that ";
  }
}
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  cout << N + N / 2 << endl;
  for(int i = 2; i <= N; i += 2) cout << i << " ";
  for(int i = 1; i <= N - 1; i += 2) cout << i << " ";
  for(int i = 2; i <= N - 2; i += 2) cout << i << " ";
  if(N % 2 == 1) cout << N << " ";
  cout << N / 2 * 2 << endl;
}
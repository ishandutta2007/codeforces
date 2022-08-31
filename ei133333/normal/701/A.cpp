#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N, all = 0;
  vector< int > A[101];
  cin >> N;
  for(int i = 0; i < N; i++) {
    int X;
    cin >> X;
    A[X].push_back(i + 1);
    all += X;
  }
  all = all * 2 / N;
  for(int i = 1; i < 101; i++) {
    while(!A[i].empty()) {
      cout << A[i].back() << " ";
      A[i].pop_back();
      cout << A[all - i].back() << endl;
      A[all - i].pop_back();
    }
  }
}
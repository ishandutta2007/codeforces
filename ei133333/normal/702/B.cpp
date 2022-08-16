#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  map< long long, int > cnt;
  long long ret = 0;

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    long long num = 1;
    for(int j = 0; j < 35; j++) {
      ret += cnt[num - A];
      num *= 2;
    }
    ++cnt[A];
  }
  cout << ret << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, l[100000];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &l[i]);
  cout << 2 * *max_element(l, l + N) - accumulate(l, l + N, 0) + 1 << endl;
}
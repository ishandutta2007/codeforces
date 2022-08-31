#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;

  scanf("%d", &N);
  int pre = -1, cnt = 0, ret = 0;
  for(int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    if(pre < A) ++cnt;
    else cnt = 1;
    pre = A;
    ret = max(ret, cnt);
  }
  printf("%d\n", ret);
}
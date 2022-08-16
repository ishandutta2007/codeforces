#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, Q;
  char buff[1505];

  scanf("%d", &N);
  scanf("%s", buff);
  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    int sz;
    char c;
    scanf("%d %c", &sz, &c);

    int ret = 0;
    int sum = 0, tail = 0;
    for(int k = 0; k < N; k++) {
      while(tail < N && sum + (buff[tail] != c) <= sz) {
        sum += buff[tail++] != c;
      }
      ret = max(ret, tail - k);
      sum -= buff[k] != c;
    }
    printf("%d\n", ret);
  }
}
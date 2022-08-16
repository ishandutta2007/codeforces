#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  int H, M;

  scanf("%d", &N);
  scanf("%d:%d", &H, &M);

  if(N == 12) {
    if(H % 10 == 0) printf("10");
    else if(H == 0) printf("01");
    else if(1 <= H && H <= 12) printf("%02d", H);
    else printf("0%d", H % 10);
  } else {
    if(0 <= H && H <= 23) printf("%02d", H);
    else printf("0%d", H % 10);
  }
  putchar(':');
  if(0 <= M && M <= 59) printf("%02d", M);
  else printf("0%d", M % 10);
}
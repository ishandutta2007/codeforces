#include<bits/stdc++.h>
using namespace std;

bool row[100001], col[100001];
int ablecol, ablerow;

int main()
{
  int N, M;
  scanf("%d %d", &N, &M);
  long long null = 1LL * N * N;
  
  for(int i = 0; i < M; i++) {
    int X, Y;
    scanf("%d %d", &X, &Y);

    if(!row[X] && !col[Y]) {
      null -= N;
      null -= N;
      null += 1;
      null += ablerow;
      null += ablecol;

      ++ablerow;
      ++ablecol;
    } else if(!row[X]) {
      null -= N;
      null += ablecol;
      ++ablerow;
    } else if(!col[Y]) {
      null -= N;
      null += ablerow;
      ++ablecol;
    }
    row[X] = col[Y] = true;
    printf("%I64d ", null);
  }
}
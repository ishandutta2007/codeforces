#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 1005

int N, M;
int r[MAX];
int c[MAX];
char m[MAX][MAX];
long long sol;

int main(void)
{
  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; ++i)
    scanf("%s", m[i]);

  for (int i = 0; i < N; ++i) 
    for (int j = 0; j < M; ++j) 
      if (m[i][j] == '*') ++r[i], ++c[j];

  for (int i = 0; i < N; ++i) 
    for (int j = 0; j < M; ++j) 
      if (m[i][j] == '*') sol += (r[i] - 1) * (c[j] - 1);

  cout << sol << endl;

  return 0;
}
#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 5e3 + 100;
inline bool mn(int& a, const int& b) {return b<a?a=b,1:0;}
void zalg(char * s, const int& N, int * z)
{
  z[0] = N;
  for(int i = 1, l, r = -1;i < N;i++)
  {
    if(i < r) z[i] = min(r-i, z[i-l]); else z[i] = 0;
    for(;i+z[i]<N&&s[i+z[i]]==s[z[i]];) z[i]++;
    if(r<i+z[i]) l = i, r = i + z[i];
  }
}
int N, A, B;
char s[MN];
int z[MN], d[MN];
void process(int i)
{
  zalg(s + i, N - i, z + i);
  d[i] = d[i+1]+A;
  for(int j = i+1, k = 1;j < N;j++)
    for(;i+k <= j&&k <= z[j];k++)
      mn(d[i], d[i+k]+B);
}
int main(void)
{
  scanf("%d%d%d %s", &N, &A, &B, s);
  for(int i = 0;i < (N>>1);i++)
    swap(s[i], s[N-i-1]);
  d[N] = 0;
  for(int i = N-1;i >= 0;i--)
    process(i);
  printf("%d\n", d[0]);
  return 0;
}
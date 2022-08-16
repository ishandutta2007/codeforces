#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  set< pair< int, int > > P;
  int S[200000];
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    int p;
    scanf("%d", &p);
    P.emplace(p, i);
  }
  for(int i = 0; i < M; i++) scanf("%d", &S[i]);


  int Pans[200000], Qans[200000];
  memset(Pans, -1, sizeof(Pans));
  memset(Qans, -1, sizeof(Qans));
  int ret = 0, sum = 0;

  for(int i = 30; i >= 0; i--) {
    for(int j = 0; j < M; j++) {
      if(~Qans[j]) continue;
      if(i != 30) S[j] = (S[j] + 1) >> 1;
      auto p = P.lower_bound({S[j], -1});
      if(p == P.end() || p->first != S[j]) continue;
      Qans[j] = 30 - i;
      Pans[p->second] = j;

      P.erase(p);
      ++ret;
      sum += 30 - i;
    }
  }

  printf("%d %d\n", ret, sum);
  for(int i = 0; i < M; i++) {
    printf("%d ", max(Qans[i], 0));
  }
  puts("");
  for(int i = 0; i < N; i++) {
    printf("%d ", Pans[i] + 1);
  }
  puts("");
}
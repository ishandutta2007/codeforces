#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100005

int N;
vector< int > d[MAXN];
vector< pair< int, int > > sol;

int np[MAXN];
int matched[MAXN];

int main(void)
{
  scanf("%d", &N);

  for (int i = 2; i <= N; ++i) {
    if (np[i]) continue;
    d[i].push_back(i);
    for (int j = 2 * i; j <= N; j += i) {
      d[i].push_back(j);
      np[j] = 1;
    }
  }

  auto match = [&sol](vector< int > &d) {
    int unmatched = -1;
    for (auto D : d) {
      if (matched[D]) continue;
      if (unmatched == -1)
        unmatched = D;
      else {
        matched[D] = 1;
        matched[unmatched] = 1;
        sol.push_back({D, unmatched});
        unmatched = -1;
      }
    }
  };

  for (int i = 3; i <= N; ++i) {
    if (np[i]) continue;

    int cnt = count_if(begin(d[i]), end(d[i]), [](int n) { 
      return !matched[n]; 
    });

    if (cnt % 2 == 1 && 2 * i <= N)
      d[i].erase(find(begin(d[i]), end(d[i]), 2 * i));
    
    match(d[i]);
  }

  match(d[2]);

  printf("%d\n", sol.size());

  for (auto p : sol) 
    printf("%d %d\n", p.first, p.second);

  return 0;
}
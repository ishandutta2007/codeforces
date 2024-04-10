#include <cstdio>
#include <vector>
#include <algorithm>

const int MN = 3e3 + 10;

typedef long long ll;

struct DPS
{
public:
  int w;
  ll v;
  DPS(int w = -10000, ll v = 0) : w(w), v(v) {}
  DPS operator + (DPS o) const {return DPS(w+o.w, v+o.v);}
  int get(void) const {return w + (v>0LL);}
  DPS cut(void) const {return DPS(w+(v>0LL), 0LL);}
  DPS operator + (ll o) const {return DPS(w, v + o);}
  bool operator < (DPS o) const {return w < o.w || !(o.w < w) && v < o.v;}
  bool operator > (DPS o) const {return w > o.w || !(o.w > w) && v > o.v;}
};

int N, M;
std::vector<int> a[MN];
int v[MN];

std::vector<DPS> pool[MN];
int pool_ctr;
std::vector<DPS> * getnew(void)
{
  return pool+(pool_ctr++);
}

std::vector<DPS> * dp[MN];
int s[MN];

void dfs(int n = 1, int p = 0)
{
  s[n] = 1;
  int ch = 0;
  for(int x : a[n])
    if(p != x)
    {
      ++ch;
      dfs(x, n);
      s[n] += s[x];
    }
  if(!ch)
  {
    dp[n] = getnew();
    dp[n]->push_back(DPS(0, v[n]));
    return;
  }
  int h = -1;
  for(int x : a[n])
    if(x != p)
      if(!~h || s[x] < s[h])
        h = x;
  
  dp[n] = dp[h];
  int q = std::min(s[h]+1, M);
  for(int i = dp[n]->size(), j = std::min(M, s[n]);i < j;++i)
    dp[n]->push_back(DPS());
  for(int i = q-1;i > 0;--i)
    dp[n]->at(i) = std::max(dp[n]->at(i)+v[n], dp[n]->at(i-1).cut() + v[n]);
  dp[n]->at(0) = dp[n]->at(0) + v[n];

  for(int x : a[n])
    if(x != p && x != h)
    {
      for(int i = q-1;i >= 0;--i)
      {
        for(int j = 0;i+j < M && j < dp[x]->size();++j)
        {
					if(i+j+1 < M) dp[n]->at(i+j+1) = std::max(dp[n]->at(i+j+1), dp[n]->at(i) + dp[x]->at(j).cut());
					if(j) dp[n]->at(i+j) = std::max(dp[n]->at(i+j), dp[n]->at(i) + dp[x]->at(j));
        }
        dp[n]->at(i) = dp[n]->at(i) + dp[x]->at(0);
      }
      q = std::min(q+s[x], M);
    }
}

void solve(void)
{
  scanf("%d%d", &N, &M);
  for(int i = 1, u;i <= N;++i)
    scanf("%d", &u), v[i] = -u;
  for(int i = 1, u;i <= N;++i)
    scanf("%d", &u), v[i] += u;
  for(int i = 0, u, v;i < N-1;++i)
    scanf("%d%d", &u, &v), a[u].push_back(v), a[v].push_back(u);
  dfs();
  printf("%d\n", dp[1]->at(M-1).get());
  for(int i = 1;i <= N;++i)
    a[i].clear();
  for(int i = 0;i < pool_ctr;++i)
    pool[i].clear();
  pool_ctr = 0;
}

int main(void)
{
  int T;
  scanf("%d", &T);
  for(int i = 1;i <= T;++i)
    solve();
  return 0;
}
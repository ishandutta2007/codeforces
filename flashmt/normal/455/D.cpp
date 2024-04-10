#include <bits/stdc++.h>
using namespace std;
const int BLOCK_SIZE = 314;

int n, a[100100], numBlock, cnt[400][100100], sz[400];
vector <int> blocks[400];

void build()
{
  for (int i = 0, id = 0; i < numBlock; i++)
  {
    for (int j = 0; j < sz[i]; j++)
    {
      a[id++] = blocks[i][j];
      cnt[i][blocks[i][j]] = 0;
    }
    blocks[i].clear();
    sz[i] = 0;
  }
  
  for (int i = 0; i < n; i++)
  {
    blocks[i / BLOCK_SIZE].push_back(a[i]);
    cnt[i / BLOCK_SIZE][a[i]]++;
    sz[i / BLOCK_SIZE]++;
  }
}

pair <int,int> find(int x)
{
  for (int i = 0, id = 0; i < numBlock; i++)
    if (id + sz[i] > x) return make_pair(i, x - id);
    else id += sz[i];
  return make_pair(-1, -1);
}

void shift(int l, int r)
{
  if (l == r) return;
  
  pair <int,int> from = find(r), to = find(l);
  int value = blocks[from.first][from.second];
  
  cnt[from.first][value]--;
  sz[from.first]--;
  blocks[from.first].erase(blocks[from.first].begin() + from.second);
    
  cnt[to.first][value]++;
  sz[to.first]++;
  blocks[to.first].insert(blocks[to.first].begin() + to.second, value);
}

int calc(int l, int r, int value)
{
  pair <int,int> from = find(l), to = find(r);
  int res = 0;
  
  if (from.first == to.first)
  {
    for (int i = from.second; i <= to.second; i++)
      res += blocks[from.first][i] == value;
    return res;
  }
  
  for (int i = from.second; i < sz[from.first]; i++)
    res += blocks[from.first][i] == value;
  
  for (int i = 0; i <= to.second; i++)
    res += blocks[to.first][i] == value;
    
  for (int i = from.first + 1; i < to.first; i++)
    res += cnt[i][value];
  
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  numBlock = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  
  int lastAns = 0, l, r, type, k, Q;
  cin >> Q;
  while (Q--)
  {
    cin >> type >> l >> r;
    l = (l + lastAns - 1) % n;
    r = (r + lastAns - 1) % n;
    if (l > r) swap(l, r);
    if (type == 1) shift(l, r);
    else
    {
      cin >> k;
      k = (k + lastAns - 1) % n + 1;
      cout << (lastAns = calc(l, r, k)) << endl;
    }

    if (Q % BLOCK_SIZE == 0) build();
  }
}
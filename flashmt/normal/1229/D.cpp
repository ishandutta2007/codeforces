#include <bits/stdc++.h>
using namespace std;
const int FACT[] = {1, 1, 2, 6, 24, 120};

int n, k, f[120][120], a[200200];
map<vector<int>, int> id;
vector<vector<int>> allP;

vector<int> doOp(vector<int> p, vector<int> op)
{
  vector<int> res(k);
  for (int i = 0; i < k; i++)
    res[op[i]] = p[i];
  return res;
}

int bfs(bitset<120> &curMask, vector<int> ops)
{
  queue<int> q;
  for (int i = 0; i < FACT[k]; i++)
    if (curMask[i])
      q.push(i);

  int foundNew = 0;
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int p : ops)
    {
      int y = f[x][p];
      if (!curMask[y])
      {
        curMask[y] = foundNew = 1;
        q.push(y);
      }
    }
  }

  return foundNew;
}


void init()
{
  vector<int> p;
  for (int i = 0; i < k; i++)
    p.push_back(i);
  do
  {
    id[p] = allP.size();
    allP.push_back(p);
  } while (next_permutation(p.begin(), p.end()));

  for (int i = 0; i < FACT[k]; i++)
    for (int j = 0; j < FACT[k]; j++)
      f[i][j] = id[doOp(allP[i], allP[j])];
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  init();
  vector<int> p(k);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      cin >> p[j];
      p[j]--;
    }
    a[i] = id[p];
  }

  long long ans = 0;
  vector<int> last(FACT[k], - 1);
  for (int i = 0; i < n; i++)
  {
    vector<int> candidates;
    for (int j = 0; j < FACT[k]; j++)
      if (last[j] >= 0)
        candidates.push_back(last[j]);
    sort(candidates.begin(), candidates.end(), greater<int>());

    vector<int> ops(1, a[i]);
    bitset<120> mask;
    mask[0] = 1;
    bfs(mask, ops);
    int lastId = i;
    for (int j : candidates)
    {
      ans += 1LL * (lastId - j) * mask.count();
      ops.push_back(a[j]);
      if (!bfs(mask, ops))
      {
        ops.pop_back();
        last[a[j]] = -1;
      }
      lastId = j;
    }
    ans += (lastId + 1LL) * mask.count();

    last[a[i]] = i;
  }

  cout << ans << endl;
}
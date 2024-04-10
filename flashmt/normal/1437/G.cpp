#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

int n, m, nodeIds[300300], lastSeen[300300], values[300300], ans[300300], types[300300];
vector<int> a[300300];
set<int> queries[300300];
vector<tuple<int, int, int>> updates[300300];

struct Node
{
  vector<int> next;
  int link;
  long long cnt;

  Node()
  {
    next = vector<int>(MAX_CHAR, -1);
    link = -1;
    cnt = 0;
  }
};

struct AhoCorasick
{
  vector<Node> nodes;

  AhoCorasick()
  {
    nodes = vector<Node>(1, Node());
  }

  int addString(const string &s)
  {
    int v = 0;
    for (char ch : s)
    {
      int c = ch - 'a';
      if (nodes[v].next[c] < 0)
      {
        nodes[v].next[c] = nodes.size();
        nodes.push_back(Node());
      }
      v = nodes[v].next[c];
    }
    return v;
  }

  int go(int v, int c)
  {
    while (v && nodes[v].next[c] < 0)
      v = nodes[v].link;
    return max(0, nodes[v].next[c]);
  }

  void buildLink()
  {
    queue<int> q;
    nodes[0].link = 0;
    for (int v : nodes[0].next)
      if (v >= 0)
      {
        q.push(v);
        nodes[v].link = 0;
        a[0].push_back(v);
      }

    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      nodes[v].cnt += nodes[nodes[v].link].cnt;
      for (int c = 0; c < MAX_CHAR; c++)
        if (nodes[v].next[c] >= 0)
        {
          int u = nodes[v].next[c];
          q.push(u);
          nodes[u].link = go(nodes[v].link, c);
          a[nodes[u].link].push_back(u);
        }
    }
  }

  void match(const string &s, int qId)
  {
    int v = 0;
    for (char ch : s)
    {
      int c = ch - 'a';
      while (v && nodes[v].next[c] < 0)
        v = nodes[v].link;
      v = max(v, nodes[v].next[c]);
      if (v)
        queries[v].insert(qId);
    }
  }
};

struct SegmentTree
{
  int low, mid, high;
  vector<int> values;
  SegmentTree *l, *r;

  SegmentTree(int low, int high): low(low), high(high)
  {
    mid = (low + high) / 2;
    values = {-1};
    if (low != high)
    {
      l = new SegmentTree(low, mid);
      r = new SegmentTree(mid + 1, high);
    }
  }

  void update(int x, int y, int v)
  {
    if (low == x && high == y) values.push_back(max(v, values.back()));
    else
    {
      if (x <= mid)
        l->update(x, min(y, mid), v);
      if (mid < y)
        r->update(max(x, mid + 1), y, v);
    }
  }

  void rollback(int x, int y)
  {
    if (low == x && high == y) values.pop_back();
    else
    {
      if (x <= mid)
        l->rollback(x, min(y, mid));
      if (mid < y)
        r->rollback(max(x, mid + 1), y);
    }
  }

  int get(int x)
  {
    if (low == high)
      return values.back();
    return max(x <= mid ? l->get(x) : r->get(x), values.back());
  }
};

SegmentTree *segTree;

void dfs(int x)
{
  sort(updates[x].begin(), updates[x].end());
  for (auto [v, l, r] : updates[x])
    segTree->update(l, r, v);
  for (int i : queries[x])
    ans[i] = max(ans[i], segTree->get(i));

  for (int y : a[x])
    dfs(y);

  for (auto [_, l, r] : updates[x])
    segTree->rollback(l, r);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  AhoCorasick aho;
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    nodeIds[i] = aho.addString(s);
  }
  aho.buildLink();

  for (int i = 1; i <= m; i++)
  {
    int x, v;
    cin >> types[i];
    if (types[i] == 1)
    {
      cin >> x >> v;
      updates[nodeIds[x]].push_back({values[x], lastSeen[x], i - 1});
      values[x] = v;
      lastSeen[x] = i;
    }
    else
    {
      string s;
      cin >> s;
      aho.match(s, i);
    }
  }

  for (int i = 1; i <= n; i++)
    updates[nodeIds[i]].push_back({values[i], lastSeen[i], m});

  memset(ans, -1, sizeof ans);
  segTree = new SegmentTree(0, m);
  dfs(0);

  for (int i = 1; i <= m; i++)
    if (types[i] == 2)
      cout << ans[i] << '\n';
}
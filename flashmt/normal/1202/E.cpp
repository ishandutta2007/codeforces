#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

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

  void addString(const string &s)
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
    nodes[v].cnt++;
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
        }
    }
  }
};

int main()
{
  string t, s;
  int m;
  cin >> t >> m;

  AhoCorasick *lAho = new AhoCorasick(), *rAho = new AhoCorasick();
  while (m--)
  {
    cin >> s;
    lAho->addString(s);
    reverse(s.begin(), s.end());
    rAho->addString(s);
  }

  lAho->buildLink();
  int v = 0;
  vector<long long> endAt(t.size(), 0);
  for (int i = 0; i < t.size(); i++)
  {
    v = lAho->go(v, t[i] - 'a');
    endAt[i] = lAho->nodes[v].cnt;
  }

  rAho->buildLink();
  v = 0;
  long long ans = 0;
  for (int i = t.size() - 1; i; i--)
  {
    v = rAho->go(v, t[i] - 'a');
    ans += rAho->nodes[v].cnt * endAt[i - 1];
  }

  cout << ans << endl;
}
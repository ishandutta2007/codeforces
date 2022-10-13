#include <bits/stdc++.h>
using namespace std;
const int C = 26;

int nodeCnt, f[2000200][2], hasParent[2000200];
vector <int> child[2000200];

struct Trie 
{
  Trie *next[C], *suffix;
  int id, length;

  Trie(int length): length(length)
  {
    id = nodeCnt++;
    hasParent[id] = 0;
    child[id].clear();
    for (int i = 0; i < C; i++)
      next[i] = NULL;
    suffix = NULL;
  }

  void add(string &s)
  {
    if (length == s.size())
      return;
    int c = s[length] - 'a';
    if (!next[c])
      next[c] = new Trie(length + 1);
    next[c] -> add(s);
  }

  void debug(int space, int c)
  {
    for (int i = 0; i < space; i++) cout << ' ';
    cout << char(c + 'a') << "(" << id << ")" << endl;
    for (int i = 0; i < C; i++)
      if (next[i])
        next[i] -> debug(space + 1, i);
  }
};

void buildAC(Trie *root)
{
  queue <Trie*> q;
  q.push(root);
  while (!q.empty())
  {
    Trie *x = q.front();
    q.pop();
    for (int i = 0; i < C; i++)
      if (x -> next[i])
      {
        Trie *y = x -> next[i];
        Trie *s = x -> suffix;
        while (s && !s -> next[i])
          s = s -> suffix;
        y -> suffix = s ? s -> next[i] : root;
        if (y -> suffix != root && y -> suffix -> length + 1 == y -> length)
        {
          child[y -> suffix -> id].push_back(y -> id);
          hasParent[y -> id] = 1;
        }
        q.push(y);
      }
  }
}

int calc(int x)
{
  f[x][0] = 0;
  f[x][1] = 1;
  for (int y : child[x])
  {
    f[x][0] += calc(y);
    f[x][1] += f[y][0];
  }
  return max(f[x][0], f[x][1]);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int test, n;
  string s;
  cin >> test;
  while (test--)
  {
    cin >> n;
    nodeCnt = 0;
    Trie *trie = new Trie(0);
    for (int i = 0; i < n; i++)
    {
      cin >> s;
      trie -> add(s);
    }
    buildAC(trie);
    int ans = 0;
    for (int i = 1; i < nodeCnt; i++)
      if (!hasParent[i])
        ans += calc(i);
    cout << ans << endl;
  }
}
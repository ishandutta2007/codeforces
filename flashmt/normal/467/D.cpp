#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

map <string,int> m;
int n, words[100100], length[500500], countR[500500], visited[500500];
vector <int> a[500500], aa[500500];
int st[500500], last, step, low[500500], num[500500], d[500500], components;
pair <int,int> f[500500], g[500500];

string toLower(string s)
{
  for (int i = 0; i < int(s.size()); i++)
    if (s[i] <= 'Z')
      s[i] = s[i] - 'A' + 'a';
  return s;
}

int get(string s)
{
  if (!m.count(s)) 
  {
    m[s] = m.size();
    int id = m[s];
    length[id] = s.size();
    for (int i = 0; i < int(s.size()); i++)
      countR[id] += s[i] == 'r';
  }
  return m[s];
}

void visit(int x)
{
  st[++last] = x;
  low[x] = num[x] = ++step;
  for (int i = 0; i < int(a[x].size()); i++)
  {
    int y = a[x][i];
    if (d[y]) continue;
    if (num[y]) low[x] = min(low[x], num[y]);
    else
    {
      visit(y);
      low[x] = min(low[x], low[y]);
    }
  }
  
  if (num[x] != low[x]) return;
  
  f[++components] = make_pair(oo, oo);
  while (1)
  {
    int y = st[last--];
    d[y] = components;
    f[components] = min(f[components], make_pair(countR[y], length[y]));
    if (y == x) break;
  }
}

void calc(int x)
{
  if (visited[x]) return;
  visited[x] = 1;
  g[x] = f[x];
  for (int i = 0; i < int(aa[x].size()); i++)
  {
    int y = aa[x][i];
    calc(y);
    g[x] = min(g[x], g[y]);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  string word, word2;
  int p;
  
  cin >> n;
  for (int i = 0; i < n; i++) 
  {
    cin >> word;
    word = toLower(word);
    words[i] = get(word);
  }
  
  cin >> p;
  while (p--)
  {
    cin >> word >> word2;
    word = toLower(word);
    word2 = toLower(word2);
    a[get(word)].push_back(get(word2));
  }
  
  for (int i = 1; i <= int(m.size()); i++)
    if (!d[i])
      visit(i);
  
  for (int x = 1; x <= int(m.size()); x++)
    for (int i = 0; i < int(a[x].size()); i++)
    {
      int y = a[x][i];
      if (d[y] != d[x]) aa[d[x]].push_back(d[y]);
    }
  
  pair <long long,long long> ans(0, 0);
  for (int i = 0; i < n; i++)
  {
    calc(d[words[i]]);
    ans.first += g[d[words[i]]].first;
    ans.second += g[d[words[i]]].second;
  }
  
  cout << ans.first << ' ' << ans.second << endl;
}
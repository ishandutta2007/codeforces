#include <bits/stdc++.h>

using namespace std;

int N;
vector< int > g[200000];
int color[200000];

void rec(int idx, int c, int par = -1)
{
  color[idx] = c;
  int s = 0;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    while(s == c || (~par && color[par] == s)) ++s;
    rec(to, s++, idx);
  }
}

int main()
{
  memset(color, -1, sizeof(color));
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  rec(0, 0);

  cout << *max_element(color, color + N) + 1 << endl;
  for(int i = 0; i < N; i++) cout << color[i] + 1 << " ";
  cout << endl;
}
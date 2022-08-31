#include<bits/stdc++.h>

using namespace std;

struct edge
{
  int to, type;
};

int N;
vector< edge > g[300000];
int add[300000];

int merge(vector< int > &child)
{
  vector< int > tmp[26];
  for(int i : child) {
    for(auto &e : g[i]) tmp[e.type].push_back(e.to);
  }
  int ret = 0;
  for(int i = 0; i < 26; i++) {
    if(tmp[i].size() > 1) {
      ret += merge(tmp[i]);
      ret += tmp[i].size() - 1;
    }
  }
  return (ret);
}

void rec(int idx, int dep)
{
  for(edge &e : g[idx]) rec(e.to, dep + 1);
  vector< int > child;
  for(edge &e : g[idx]) child.push_back(e.to);
  add[dep] -= merge(child) + g[idx].size();
}


int main()
{
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    g[--a].push_back((edge) {--b, c - 'a'});
  }

  for(int i = 0; i < N; i++) add[i] = N;
  rec(0, 0);
  auto p = min_element(add, add + N);
  cout << *p << endl << p - add + 1 << endl;
}
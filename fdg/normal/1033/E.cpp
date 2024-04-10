#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>
#include <sstream>

using namespace std;

int n;
vector<int> g[605];
 
set<int> known, all;

map<string, int> cache;

string toString(const set<int> &f) {
  ostringstream ss;
  for (int x : f)
    ss << x << ",";
  return ss.str();
}

void toCache(const set<int> &f1, int val) {
  cache[toString(f1)] = val;
}

void toCache(const set<int> &f1, const set<int> &f2, int val) {
  set<int> f = f1;
  for (int x : f2)
    f.insert(x);

  toCache(f, val);
}

int queryCount = 0;

int get(const set<int> &f1) {
  if (f1.size() <= 1)
    return 0;

  if (cache.count(toString(f1))) {
    return cache[toString(f1)];
  }

  ++queryCount;

  cout << "? " << f1.size() << endl;
  for (int x : f1)
    cout << x << " ";

  int ret;
  cin >> ret;

  return cache[toString(f1)] = ret;
}

int get(const set<int> &f1, const set<int> &f2) {
  set<int> f = f1;
  for (int x : f2)
    f.insert(x);

  return get(f);
}

void addEdge(pair<int, int> e) {
  g[e.first].push_back(e.second);
  g[e.second].push_back(e.first);

  known.insert(e.second);
  all.erase(e.second);
}

pair<int, int> find(const set<int> &a, const set<int> &b, /*int total,*/ int valA, int valB) {
  // toCache(a, valA);
  toCache(b, valB);
  // toCache(a, b, total);


  if (a.size() == 1 && b.size() == 1) {
    // addEdge(make_pair(*a.begin(), *b.begin()));
    return make_pair(*a.begin(), *b.begin());
  }

  if (a.size() > 1) {
    set<int> a1, a2;
    for (int x : a) {
      if (a1.size() < a.size() / 2) a1.insert(x);
      else a2.insert(x);
    }

    int valA1 = get(a1), valA1B = get(a1, b);
    if (valA1B - valB - valA1 > 0)
      return find(a1, b, /*valA1B,*/ /* valA1 */ 0, valB);
    else {
      return find(a2, b, /*get(a2, b),*/ /*get(a2)*/ 0, valB);
    }
  }

  {
    set<int> b1, b2;
    for (int x : b) {
      if (b1.size() < b.size() / 2) b1.insert(x);
      else b2.insert(x);
    }

    int valB1 = get(b1), valAB1 = get(a, b1);

    int tmp = valAB1 - /* valA= */ 0 - valB1;

    // if (tmp != get(a, b) - valA - valB)
    //   find(a, b2, /*total,*/ valA, get(b2));

    if (tmp > 0)
      return find(a, b1, /*valAB1,*/ /* valA= */ 0, valB1);
    else
      return find(a, b2, /*get(a, b2), */ /* valA= */ 0, get(b2));
  }
}

pair<int, int> find(const set<int> &a, const set<int> &b) {
  return find(a, b, /*get(a, b),*/ /*get(a)*/ 0, get(b));
}

pair<int, int> getEdge(const set<int> &f) {
  // if (queryCount >= 19000)
  //   exit(-1);

  int valF = get(f);
  for (int x : f) {
    set<int> tmp = f;
    tmp.erase(x);

    int valTmp = get(tmp);
    if (valTmp != valF) {
      set<int> a;
      a.insert(x);
      return find(a, tmp, /*valF,*/ 0, valTmp);
    }
  }

  return {-1, -1};
}

int color[605];

void go(int v, int col) {
  if (color[v] != 0) return;

  color[v] = col;
  for (int x : g[v])
    go(x, 3 - col);
}

vector<int> path;

bool findPath(int st, int fn) {
  if (color[st] != 0) return false;

  path.push_back(st);
  color[st] = 1;

  if (st == fn) return true;

  for (int x : g[st])
    if (findPath(x, fn))
      return true;

  path.pop_back();

  return false;
}

int main() {
  cin >> n;

  known.insert(1);
  for (int i = 2; i <= n; ++i)
    all.insert(i);

  for (int i = 2; all.size() > 0; ++i) {
    pair<int, int> e = find(known, all);
    addEdge(e);

    // if (queryCount >= 19000) {
    //   cout << "N " << known.size() << endl;
    //   return 0;
    // }
  }

  go(1, 1);
  set<int> l, r;
  for (int i = 1; i <= n; ++i)
    if (color[i] == 1) l.insert(i);
    else r.insert(i);

  int v1 = get(l), v2 = get(r);
  if (v1 == 0 && v2 == 0) {
    cout << "Y " << l.size() << endl;
    for (int x : l)
      cout << x << " ";
    cout << endl;
  } else {
    pair<int, int> e = getEdge((v1 > 0) ? l : r);

    memset(color, 0, sizeof(color));
    findPath(e.first, e.second);

    cout << "N " << path.size() << endl;
    for (int x : path)
      cout << x << " ";
    cout << endl;
  }

  return 0;
}
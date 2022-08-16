#include<bits/stdc++.h>

using namespace std;

class ConvexHullDynamic
{
  typedef long long coef_t;
  typedef long long coord_t;
  typedef long long val_t;

  /*
   * Line 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
   * and 'xLeft' which is intersection with previous line in hull(first line has -INF)
   */
private:
  struct Line
  {
    coef_t a, b;
    double xLeft;

    enum Type
    {
      line, maxQuery, minQuery
    } type;
    coord_t val;

    explicit Line(coef_t aa = 0, coef_t bb = 0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}

    val_t valueAt(coord_t x) const { return a * x + b; }

    friend bool areParallel(const Line &l1, const Line &l2) { return l1.a == l2.a; }

    friend double intersectX(const Line &l1, const Line &l2) { return areParallel(l1, l2) ? INFINITY : 1.0 * (l2.b - l1.b) / (l1.a - l2.a); }

    bool operator<(const Line &l2) const
    {
      if(l2.type == line)
        return this->a < l2.a;
      if(l2.type == maxQuery)
        return this->xLeft < l2.val;
      if(l2.type == minQuery)
        return this->xLeft > l2.val;
    }
  };


  bool isMax; //whether or not saved envelope is top(search of max value)
public:
  std::set< Line > hull;  //envelope itself

private:
  /*
   * INFO:        Check position in hull by iterator
   * COMPLEXITY:  O(1)
   */
  bool hasPrev(std::set< Line >::iterator it) { return it != hull.begin(); }

  bool hasNext(std::set< Line >::iterator it) { return it != hull.end() && std::next(it) != hull.end(); }

  /*
   * INFO:        Check whether line l2 is irrelevant
   * NOTE:        Following positioning in hull must be true
   *              l1 is next left to l2
   *              l2 is right between l1 and l3
   *              l3 is next right to l2
   * COMPLEXITY:  O(1)
   */
  bool irrelevant(const Line &l1, const Line &l2, const Line &l3) { return intersectX(l1, l3) <= intersectX(l1, l2); }

  bool irrelevant(std::set< Line >::iterator it)
  {
    return hasPrev(it) && hasNext(it)
           && (isMax && irrelevant(*std::prev(it), *it, *std::next(it))
               || !isMax && irrelevant(*std::next(it), *it, *std::prev(it)));
  }

  /*
   * INFO:        Updates 'xValue' of line pointed by iterator 'it'
   * COMPLEXITY:  O(1)
   */
  std::set< Line >::iterator updateLeftBorder(std::set< Line >::iterator it)
  {
    if(isMax && !hasPrev(it) || !isMax && !hasNext(it))
      return it;

    double val = intersectX(*it, isMax ? *std::prev(it) : *std::next(it));
    Line buf(*it);
    it = hull.erase(it);
    buf.xLeft = val;
    it = hull.insert(it, buf);
    return it;
  }

public:
  explicit ConvexHullDynamic(bool isMax) : isMax(isMax) {}

  /*
   * INFO:        Adding line to the envelope
   *              Line is of type 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
   * COMPLEXITY:  Adding N lines(N calls of function) takes O(N*log N) time
   */
  void addLine(coef_t a, coef_t b)
  {
    //find the place where line will be inserted in set
    Line l3 = Line(a, b);
    auto it = hull.lower_bound(l3);

    //if parallel line is already in set, one of them becomes irrelevant
    if(it != hull.end() && areParallel(*it, l3)) {
      if(isMax && it->b < b || !isMax && it->b > b)
        it = hull.erase(it);
      else
        return;
    }

    //try to insert
    it = hull.insert(it, l3);
    if(irrelevant(it)) {
      hull.erase(it);
      return;
    }

    //remove lines which became irrelevant after inserting line
    while(hasPrev(it) && irrelevant(std::prev(it))) hull.erase(std::prev(it));
    while(hasNext(it) && irrelevant(std::next(it))) hull.erase(std::next(it));

    //refresh 'xLine'
    it = updateLeftBorder(it);
    if(hasPrev(it))
      updateLeftBorder(std::prev(it));
    if(hasNext(it))
      updateLeftBorder(std::next(it));
  }

  val_t getBest(coord_t x) const
  {
    Line q;
    q.val = x;
    q.type = isMax ? Line::Type::maxQuery : Line::Type::minQuery;

    auto bestLine = hull.lower_bound(q);
    if(isMax) --bestLine;
    return bestLine->valueAt(x);
  }
};

using int64 = long long;

int N, A[100000], B[100000];
vector< int > g[100000];
int64 best[100000];
vector< ConvexHullDynamic > chd;

void rec(int idx, int par)
{
  if(~par && g[idx].size() == 1) {
    best[idx] = 0;
    chd[idx].addLine(B[idx], best[idx]);
    return;
  }

  for(auto &to : g[idx]) {
    if(to == par) continue;
    rec(to, idx);
    if(chd[idx].hull.size() < chd[to].hull.size()) swap(chd[idx], chd[to]);
    for(auto &x: chd[to].hull) {
      chd[idx].addLine(x.a, x.b);
    }
    chd[to].hull.clear();
  }


  best[idx] = chd[idx].getBest(A[idx]);
  chd[idx].addLine(B[idx], best[idx]);

}

int main()
{
  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for(int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }
  for(int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  chd.assign(N, ConvexHullDynamic(false));
  rec(0, -1);
  for(int i = 0; i < N; i++) {
    printf("%lld ", best[i]);
  }
  puts("");
}
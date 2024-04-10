#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);

template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

void pc();
template<class T, class... Ts> void pc(const T& t, const Ts&... ts);

#define dbg(x...) pr("[",#x,"] = ["), pc(x);


typedef pair<int, int> pii;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int xm, ym, zm, n, m, k;
int xmin, xmax, ymin, ymax, zmin, zmax;

vector< pii > tree[200010];
vector< int > ys[200010];

const int inf = 1e9;
pii fakequery(int l, int r, int ly, int ry) {
    for (l += xm, r += xm; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            ys[l].push_back(ly);
            ys[l].push_back(ry);
            l++;
        }
        if (r&1) {
            --r;
            ys[r].push_back(ly);
            ys[r].push_back(ry);
        }
    }
    return {0,0};
}

void fakeset(int p, int ly, int value) {  // set value at position p
  p += xm;
  ys[p].push_back(ly);
  for (; p > 1; p >>= 1) {
      ys[p>>1].push_back(ly);
  }
}

void join(pii& a, pii b) {
    if (b.first <= zmax) a.first = max(a.first, b.first);
    if (b.second >= zmin) a.second = min(a.second, b.second);
}

void modify3(int p, int y, int value) {
    join(tree[p][y], {value, value});
}

void modify2(int p, int ly, int value) {
    int yn = ys[p].size();
    int ny = lower_bound(ys[p].begin(), ys[p].end(), ly) - ys[p].begin();
    for (modify3(p, ny += yn, value); ny > 1; ny >>= 1) modify3(p, ny>>1, value);  
}

void upd(int p, int ly,int value) {  // set value at position p
    for (modify2(p += xm, ly, value); p > 1; p >>= 1) modify2(p>>1, ly, value);
}

pii query2(int p, int ly, int ry) {
    pii res = {-inf, inf};
    int yn = ys[p].size();
    int l = lower_bound(ys[p].begin(), ys[p].end(), ly) - ys[p].begin();
    int r = lower_bound(ys[p].begin(), ys[p].end(), ry) - ys[p].begin();

    for (l += yn, r += yn; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            join(res, tree[p][l++]);
        } 
        if (r&1) {
            join(res, tree[p][--r]);
        }
    }
    return res;
}

pii query(int l, int r, int ly, int ry) {  // sum on interval [l, r)
  pii res = {-inf, inf};
  for (l += xm, r += xm; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
        pii p = query2(l++, ly, ry);
        join(res, p);
    } 
    if (r&1) {
        pii p = query2(--r, ly, ry);
        join(res, p);
    }
  }
  return res;
}

void push() {
    for (int i = 0; i < 2*xm; i++) {
        sort(ys[i].begin(), ys[i].end());
        ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
        tree[i].resize(ys[i].size() * 2, {-inf, inf});
    }
}


vector< pair<int, pii> > closed;
vector< pair<int, pii> > queries;

void solve()
{
    re(xm, ym, zm, n, m, k); xm++; ym++; zm++;
    xmin = ymin = zmin = 110000;
    xmax = ymax = zmax = -1;

    REP(i,n) {
        int x,y,z;
        re(x,y,z);
        xmin = min(xmin,x); xmax = max(xmax,x);
        ymin = min(ymin,y); ymax = max(ymax,y);
        zmin = min(zmin,z); zmax = max(zmax,z);
    }

    closed.resize(m);
    REP(i, m) {
        re(closed[i].first, closed[i].second.first, closed[i].second.second);

        int x, y, z;
        tie(x,y,z) = tuple<int,int,int>(closed[i].first, closed[i].second.first, closed[i].second.second);

        if (xmin > x || xmax < x ||
            ymin > y || ymax < y || 
            zmin > z || zmax < z) {}
        else {
            ps("INCORRECT");
            return;
        }

        fakeset(x,y,z);
    }

    ps("CORRECT");

    queries.resize(k);
    REP(i,k) {
        re(queries[i].first, queries[i].second.first, queries[i].second.second);

        int x,y,z;
        tie(x,y,z) = make_tuple(queries[i].first, queries[i].second.first, queries[i].second.second);

        if (xmin <= x && x <= xmax &&
            ymin <= y && y <= ymax &&
            zmin <= z && z <= zmax) {
                continue;
        } 

        int txmi = min(xmin, x), txma = max(xmax, x);
        int tymi = min(ymin, y), tyma = max(ymax, y);

        pii ret = fakequery(txmi,txma+1,tymi,tyma+1);
    }

    push();

    REP(i, m) {
        upd(closed[i].first, closed[i].second.first, closed[i].second.second);
    }

    REP(i, k) {
        int x,y,z;
        tie(x,y,z) = make_tuple(queries[i].first, queries[i].second.first, queries[i].second.second);

        if (xmin <= x && x <= xmax &&
            ymin <= y && y <= ymax &&
            zmin <= z && z <= zmax) {
                ps("OPEN");
                continue;
        } 

        int txmi = min(xmin, x), txma = max(xmax, x);
        int tymi = min(ymin, y), tyma = max(ymax, y);
        int tzmi = min(zmin, z), tzma = max(zmax, z);
        
        pii ret = query(txmi,txma+1,tymi,tyma+1);
        if (ret.first >= tzmi || ret.second <= tzma) ps("CLOSED");
        else ps("UNKNOWN");
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }

template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}

void pc() { pr("]\n"); }
template<class T, class... Ts> void pc(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(", "); pc(ts...); 
}
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


#include <tuple>


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr();


void pr(const char *x);


template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n;

struct universe {
    set< pair<int, int> > sorted_x;
    set< pair<int, int> > sorted_y;

    void add(int x, int y) {
        sorted_x.insert({x,y});
        sorted_y.insert({y,x});
    }
};

int used = 1;
vector<universe> universes(110000);

void split(int idx) {
    universe& u = universes[idx];

    auto xb = u.sorted_x.begin();
    auto xe = --u.sorted_x.end();
    auto yb = u.sorted_y.begin();
    auto ye = --u.sorted_y.end();

    while (xe != u.sorted_x.begin()) {
        int cx = xb->first;
        if (cx + 1 < (++xb)->first) {
            while (xb != u.sorted_x.begin()) {
                --xb;
                int x = xb->first, y = xb->second;
                universes[used].add(x,y);
                xb = u.sorted_x.erase(xb);
                u.sorted_y.erase({y,x});
            }

            split(used++);
            split(idx);
            return;
        }

        cx = xe->first;
        if ((--xe)->first + 1 < cx) {
            ++xe;
            while (xe != u.sorted_x.end()) {
                int x = xe->first, y = xe->second;
                universes[used].add(x,y);
                xe = u.sorted_x.erase(xe);
                u.sorted_y.erase({y,x});
            }

            split(used++);
            split(idx);
            return;
        }

        int cy = yb->first;
        if (cy + 1 < (++yb)->first) {
            while (yb != u.sorted_y.begin()) {
                --yb;
                int y = yb->first, x = yb->second;
                universes[used].add(x,y);
                yb = u.sorted_y.erase(yb);
                u.sorted_x.erase({x,y});
            }

            split(used++);
            split(idx);
            return;
        }

        cy = ye->first;
        if ((--ye)->first + 1 < cy) {
            ++ye;
            while (ye != u.sorted_y.end()) {
                int y = ye->first, x = ye->second;
                universes[used].add(x,y);
                ye = u.sorted_y.erase(ye);
                u.sorted_x.erase({x,y});
            }

            split(used++);
            split(idx);
            return;
        }
    }
}

void solve()
{
    re(n);
    rep(i,0,n) {
        int a, b; re(a,b);
        universes[0].add(a,b);
    }

    split(0);
    printf("%d\n", used);
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}


void pr() {}


void pr(const char *x) { printf("%s", x); }


template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
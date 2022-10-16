#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>


using namespace std;


#include <cmath>

void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#include <array>


typedef pair<int, int> pii;


#define all(v) (v).begin(), (v).end()


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int e, s, n, m;

int query[210000];
pii sta[210000];
vector<pii> ev;
pii ans[210000];
int has[10];

void solve()
{
    re(e,s,n,m);

    rep(i,0,n) re(sta[i].first,sta[i].second);
    rep(i,0,m) re(query[i]);

    rep(i,0,n) {
        ev.emplace_back(max(-e, -sta[i].second - s), sta[i].first);
        ev.emplace_back(max(-e, -sta[i].second), -sta[i].first);
    }
    rep(i,0,m) {
        ev.emplace_back(max(-e, -query[i] - s), i+200);
    }

    sort(all(ev));

    pii cur = {0,0};
    int la = -e;
    for (pii p : ev) {
        if (p.first != la) {
            if (has[3]) {}
            else if (has[2] && cur.first != -1) cur.second += (p.first - la);
            else if (has[1] && cur.first != -1) cur.first += (p.first - la);
            else cur = {-1,-1};
        }

        la = p.first;
        if (p.second < 200) {
           if (p.second < 0) has[ (-p.second)]--;
           else has[ p.second ]++; 
        }
        else {
            ans[p.second - 200] = cur;
        }
    }

    rep(i,0,m) ps(ans[i].first, ans[i].second);
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


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
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


void pr(int x);


void pr(char x);
void pr(const char *x);


template<class T> void pr(const std::vector<T> x);
template<class T, class... Ts> void pr(const T& t, const Ts&... ts);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#include <array>


typedef vector<int> vi;


#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define rep(i, a, b) for(int i = a; i < (b); ++i)


int n;

int query(const vector<int>& v) {
    if (sz(v) == 1) return 0;
    ps("?",sz(v));
    ps(v);
    fflush(stdout);
    int k; re(k);
    if (k == -1) exit(0);
    return k;
}

int query2(const vector<int>& v1, const vi& v2) {
    if (sz(v1) + sz(v2) == 1) return 0;
    ps("?",sz(v1)+sz(v2));
    trav(x,v1) pr(x,' ');
    trav(x,v2) pr(x,' ');
    ps();
    fflush(stdout);
    int k; re(k);
    if (k == -1) exit(0);
    return k;
}

int gg;
int gen[710];
int fr[710];

int get_ancestor(vi& left, int dest) {
    int st = 0, ed = sz(left);
    while (st < ed) {
        int md = (st+ed)/2;
        vector<int> q; for (int i = 0; i <= md; i++) q.push_back(left[i]);
        q.push_back(dest);
        if (query(q)) ed = md;
        else st = md+1;
    }
    return st < sz(left) ? left[st] : -1;
}

bool expand(vi &left, vi &right, vi& rem, int tot = -1, int dpt = 0) {
    //dbg(sz(rem), dpt);
    if (tot == 0 || sz(rem) == 0) return false;
    if (rem.size() == 1 && tot > 0) {
        //dbg("removing!", rem[0]);
        gen[rem[0]] = --gg;
        fr[rem[0]] = get_ancestor(left, rem[0]);
        //dbg(fr[rem[0]])
        right.push_back(rem[0]);
        rem.clear();
        return true;
    }

    vector<int> remright;
    bool found = false;

    int md = (sz(rem)+1)/2;
    for (int i = md; i < sz(rem); i++) remright.push_back(rem[i]);
    rem.erase(rem.begin()+md, rem.end());
    
    int hm = query2(left, rem) - query(rem);
    found |= expand(left, right, rem, hm,dpt+1);
    found |= expand(left, right, remright, tot - hm,dpt+1);

    rem.insert(rem.end(), all(remright));

    return found;   
}

void err(vi &left) {
    vector<int> ot;
    for (int x : left) {
        int anc = get_ancestor(ot, x);
        if (anc == -1) {
            ot.push_back(x);
            continue;
        }

        vector<int> cyc_x = {x};
        vector<int> cyc_anc = {anc};

        while (cyc_x.back() != cyc_anc.back()) {
            //dbg(cyc_x.back(), cyc_anc.back(), gen[cyc_x.back()],gen[cyc_anc.back()]);
            if (gen[cyc_x.back()] > gen[cyc_anc.back()]) swap(cyc_x, cyc_anc);
            cyc_x.push_back(fr[cyc_x.back()]);
        }

        ps("N", sz(cyc_x) + sz(cyc_anc) - 1);
        for (int y : cyc_x) pr(y,' ');
        for (int i = ((int)cyc_anc.size())-2; i >= 0; i--) pr(cyc_anc[i],' ');
        fflush(stdout);
        return;
    }
}

void reconstruct() {
    vector<int> rem;
    vector<int> left;
    vector<int> right;

    rep(i,0,n) rem.push_back(i+1);
    while (!rem.empty()) {
        int k = rand()%(rem.size());
        
        gen[rem[k]] = --gg;
        fr[rem[k]] = -1;
        left.push_back(rem[k]);
        rem.erase(rem.begin()+k);

        while (1) {
            if (!expand(left, right, rem)) break;
            if (query(right)) {
                err(right);
                return;
            }   
            if (!expand(right, left, rem)) break;
            if (query(left)) {
                err(left);
                return;
            }
        }
    }

    ps("Y", sz(left));
    ps(left);
    fflush(stdout);
    return;

}

#include <ctime>
void solve()
{
    srand(time(0));
    re(n);
    reconstruct();
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


void pr(int x) { printf("%d", x); }


void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }


template<class T> void pr(std::vector<T> v) {
    int f=0;
    for (int x : v) {
        if (f++) pr(' ');
        pr(x);
    }
}
template<class T, class... Ts> void pr(const T& t, const Ts&... ts) { 
    pr(t); pr(ts...); 
}

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
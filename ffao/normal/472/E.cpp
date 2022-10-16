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


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef pair<int, int> pii;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int n, m;
int src[30][30];
int tgt[30][30];

map<int, int> cntsrc, cntgt;
vector< pii > moves;

void do_swap(int x1, int y1, int x2, int y2) {
    //printf("swap %d %d %d %d\n", x1, y1, x2, y2);
    if (x1 == x2) {
        if (y2 < y1) swap(y1,y2);
        int tx1 = (x1 != 0 ? x1-1 : 1);

        int curr = 0;
        while (curr < tx1 && curr < y1) {
            curr++; moves.push_back({curr, curr}); 
        }
        for (int i = curr+1; i <= tx1; i++) moves.push_back({i, curr});
        for (int i = curr+1; i <= y1; i++) moves.push_back({tx1, i});
        moves.push_back({x1, y1}); moves.push_back({x1, y2});
        for (int i = y1; i >= curr; i--) moves.push_back({tx1, i});
        for (int i = tx1-1; i >= curr; i--) moves.push_back({i, curr});
        for (int i = curr-1; i >= 0; i--) moves.push_back({i, i});
    }
    else {
        if (x2 < x1) swap(x1,x2);
        int ty1 = (y1 != 0 ? y1-1 : 1);

        int curr = 0;
        while (curr < ty1 && curr < x1) {
            curr++; moves.push_back({curr, curr});
        }
        for (int i = curr+1; i <= ty1; i++) moves.push_back({curr, i});
        for (int i = curr+1; i <= x1; i++) moves.push_back({i, ty1});
        moves.push_back({x1, y1}); moves.push_back({x2, y1});
        for (int i = x1; i >= curr; i--) moves.push_back({i, ty1});
        for (int i = ty1-1; i >= curr; i--) moves.push_back({curr, i});
        for (int i = curr-1; i >= 0; i--) moves.push_back({i, i});
    }

    swap(src[x1][y1], src[x2][y2]);
}

void solve()
{
    re(n,m);
    REP(i,n) REP(j,m) {
        re(src[i][j]);
        cntsrc[src[i][j]]++;
    }
    REP(i,n) REP(j,m) {
        re(tgt[i][j]);
        cntgt[tgt[i][j]]++;
    }

    for (auto it : cntsrc) {
        if (cntgt[it.first] != it.second) {
            ps(-1);
            return;
        }
    }

    if (n == 1) {
        REP(f, m) REP(s, m) {
            vector<int> fst;
            vector<int> snd;
            REP(k,m) if (k != f) fst.push_back(src[0][k]);
            REP(k,m) if (k != s) snd.push_back(tgt[0][k]);

            if (fst == snd) {
                ps(abs(f-s));
                int d = ((s < f) ? -1 : 1);
                for (int c = f; c != s; c += d) {
                    ps(1, c+1);
                }
                ps(1,s+1);
                return;
            }
        }

        ps(-1);
        return;
    }

    if (m == 1) {
        REP(f, n) REP(s, n) {
            vector<int> fst;
            vector<int> snd;
            REP(k,n) if (k != f) fst.push_back(src[k][0]);
            REP(k,n) if (k != s) snd.push_back(tgt[k][0]);

            if (fst == snd) {
                ps(abs(f-s));
                int d = ((s < f) ? -1 : 1);
                for (int c = f; c != s; c += d) {
                    ps(c+1, 1);
                }
                ps(s+1,1);
                return;
            }
        }

        ps(-1);
        return;
    }

    int mvx = 0, mvy = 0;
    REP(i,n) REP(j,m) if (tgt[0][0] != src[0][0] && tgt[i][j] == src[0][0]) {
        mvx = i; mvy = j;

        for (int k = j; k >= 1; k--) tgt[i][k] = tgt[i][k-1];
        for (int k = i; k >= 1; k--) tgt[k][0] = tgt[k-1][0];
        tgt[0][0] = src[0][0];
    }

    
    while (true) {
        bool found = false;
        REP(i,n) REP(j,m) if (src[i][j] != tgt[i][j]) {
            found = true;
            //printf("%d %d\n", i, j);
            REP(a,n) REP(b,m) {
                if (make_pair(a,b) > make_pair(i,j) && src[a][b] == tgt[i][j]) {
                    //printf("moving %d %d to %d %d\n", a,b,i,j);

                    int d = ((j < b) ? -1 : 1);
                    for (int k = b; k != j; k += d) {
                        do_swap(a, k, a, k+d);
                    }

                    d = ((i < a) ? -1 : 1);
                    for (int k = a; k != i; k += d) {
                        do_swap(k, j, k+d, j);
                    }                    

                    goto out;
                }
            }
        }
out:
        if (!found) break;
    }

    for (int i = 1; i <= mvx; i++) moves.push_back( {i, 0} );
    for (int i = 1; i <= mvy; i++) moves.push_back( {mvx, i} );

    ps((int)moves.size());
    ps(1,1);
    REP(i,moves.size()) ps(moves[i].first+1, moves[i].second+1);
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
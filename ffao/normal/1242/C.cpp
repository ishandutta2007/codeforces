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

#include <tuple>


void re(int& x);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


using namespace std;


#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int n;
int can[40000];
int fr[40000];
pair<int, int> ans[30];
vector<long long> sums;
map<long long, int> where;

void go(int bm) {
    if (bm == 0) return;

    if (can[bm] != -1) {
        go(can[bm]);
        go(bm ^ can[bm]);
        return;
    }

    int cur = fr[bm];
    int tcur = cur;
    do {
        int loc = where[tcur];
        tcur -= sums[where[tcur]];
        ans[where[tcur]] = {tcur, loc+1};
    } while (tcur != cur);
}

void solve()
{
    re(n);
    
    vector<set<int>> boxes(n);
    sums.resize(n);

    set<int> seen;

    long long tot = 0;

    rep(i,n){
        int k; re(k);
        rep(j,k) {
            int a; re(a);
            boxes[i].insert(a);
            tot += a;
            sums[i] += a;
            where[a] = i;
        }
    }

    if (tot % n != 0) {
        ps("No");
        return;
    }

    tot /= n;
    rep(i,n) sums[i] -= tot;
    
    set<int> gbseen;
    for (int i = 0; i < n; i++) {
        for (int x : boxes[i]) {

            long long cur = x;
            set<int> seen;

            bool ok = true;
            while (!seen.count(cur)) {
                if (gbseen.count(cur)) {
                    ok = false;
                    break;
                }
                gbseen.insert(cur);
                seen.insert(cur);
                //printf("from %lld to ... ", cur);
                cur -= sums[where[cur]];
                //printf("%lld!\n", cur);
                if (where.find(cur) == where.end()) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            int bm = 0;
            long long tcur = cur;
            do {
                if (bm & (1<<where[tcur])) {
                    bm = 0;
                    break;
                }

                bm |= (1<<where[tcur]);
                tcur -= sums[where[tcur]];
            } while (cur != tcur);

            can[bm] = -1;
            fr[bm] = cur;
        }
    }

    for (int bm = 1; bm < (1<<n); bm++) if (!can[bm]) {
        for (int ss = bm; ss != 0; ss = (ss-1)&bm) {
            if (can[ss] && can[ss^bm]) {
                can[bm] = ss;
                break;
            }
        }
    }

    if (!can[(1<<n)-1]) {
        ps("No");
        return;
    }

    ps("Yes");
    go((1<<n) - 1);
    for (int i = 0; i < n; i++) {
        ps(ans[i].first, ans[i].second);
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
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


typedef pair<int, int> pii;


#define all(v) (v).begin(), (v).end()


#define rep(i, a, b) for(int i = a; i < (b); ++i)


int L,n,p,t;
int ans;
vector< pii > intervals;
pair<int, int> opt[100000][2];

void ad(int i, int x, int val) {
    if (val > opt[i][0].second || opt[i][0].first == -1) {
        swap(opt[i][0], opt[i][1]);
        opt[i][0] = {x,val};
    }
    else if (val == opt[i][0].second) {
        opt[i][0].first = min(opt[i][0].first, x); 
    }
    else if (val > opt[i][1].second || opt[i][1].first == -1) {
        opt[i][1] = {x,val};
    }
    else if (val == opt[i][1].second) {
        opt[i][1].first = min(opt[i][1].first, x);
    }
}

void add(int x, int val) {
    //printf("add %d %d\n", x, val);
    ans = max(ans, val);

    auto it = lower_bound(all(intervals), pii{x,0});
    if (it == intervals.end()) return;
    if (it->second > x) x = it->second;
    
    int i = it - intervals.begin();
    if (i+1 < n) {
        ad(i+1, intervals[i+1].second, val);
    }

    int backtrack = (x - it->second)/p;
    x -= backtrack * p;
    val -= backtrack;
    
    ad(i, x, val);
    //printf("turned into %d %d to interval %d\n", x, val, i);
}

void solve()
{
    re(L,n,p,t);
    rep(i,0,n) {
        int a,b;
        re(a,b);
        intervals.push_back({b,a});
    }

    memset(opt,-1,sizeof(opt));

    add(0, 0);
    for (int i = 0; i < n; i++) {
        if (opt[i][0].first != -1) {
            int x = opt[i][0].first;
            int sing = (intervals[i].first - x) / p;
            int sing_this = sing + opt[i][0].second;
            
            int tgt = max(intervals[i].first + 1, x + sing*p + t);
            add(tgt, sing_this);
            add(intervals[i].first + 1, opt[i][0].second);
        }
        if (opt[i][1].first != -1) {
            int x = opt[i][1].first;
            int sing = (intervals[i].first - x) / p;
            int sing_this = sing + opt[i][1].second;
            
            int tgt = max(intervals[i].first + 1, x + sing*p + t);
            add(tgt, sing_this);
            add(intervals[i].first + 1, opt[i][1].second);
        }
    }

    printf("%d\n", ans);
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}
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


template<class T> void re(std::vector<T>& a);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


typedef pair<int, int> pii;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int cm[70][70][1831];

int m;
vector<int> a;
int g[71][71];

void solve()
{
    memset(cm,-1,sizeof(cm));

    re(m);
    a.resize(m); re(a);
    sort(a.begin(), a.end());

    cm[0][0][0] = 1;
    REP(i,m) {
        REP(c,61) {
            for (int s = 0; s <= 1830 - a[i]; s++) {
                if (cm[i][c][s] != -1 && s + a[i] >= (c+1)*c/2) cm[i+1][c+1][s + a[i]] = i;
                else if (cm[i+1][c][s] != -1 && s + a[i] >= (c+1)*c/2) cm[i+1][c+1][s + a[i]] = i+1; 
            }
        }
    }

    for (int ans = 1; ans <= 61; ans++) {
        if (cm[m][ans][ans*(ans-1)/2] != -1) {
            //ps(m,ans,ans*(ans-1)/2);
            vector< pii > members;

            int curm = m;
            int curs = ans*(ans-1)/2;

            for (int i = ans; i > 0; i--) {
                int nxt = cm[curm][i][curs];
                members.push_back({-a[curm - 1], i-1});
                //printf("push back %d\n", curm-1);

                curs -= a[curm - 1];
                curm = nxt;
            }

            for (int i = 0; i < ans; i++) {
                sort(members.begin(), members.end());
                int lose = (ans - i - 1) + members[0].first;
                for (int j = 1; j <= lose; j++) {
                    g[members[j].second][members[0].second] = 1;
                    members[j].first++;
                };
                for (int j = lose+1; j < members.size(); j++) {
                    g[members[0].second][members[j].second] = 1;
                }

                members.erase(members.begin());
            }

            ps(ans);
            REP(i, ans) {
                REP(j,ans) pr(g[i][j]);
                ps();
            }

            return;
        }
    }

    printf("=(\n");
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


template<class T> void re(std::vector<T>& a) { for (int i = 0; i < a.size(); i++) re(a[i]); }


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
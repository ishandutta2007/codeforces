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


template<class T, class... Ts> void re(T& t, Ts&... ts);


void pr(int x);


void pr(char x);
void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


using namespace std;


#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int n,m;
char board[1100][1100];
int seen[1100][1100];
vector< pair<char, pair<int, int> > > ops;

void dfs(int x, int y, bool in) {
    ops.push_back({'B', {x+1, y+1}});
    seen[x][y] = 1;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) if (dx*dy == 0 && dx+dy!=0) {
            int nx = x+dx, ny = y+dy;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] != '#' && !seen[nx][ny]) {
                dfs(nx,ny,false);
            }
        }
    }

    if (!in) {
        ops.push_back({'D', {x+1, y+1}});
        ops.push_back({'R', {x+1, y+1}});
    }
}

void solve()
{
    re(n,m);
    rep(i,n) scanf("%s", board[i]);

    rep(i,n) rep(j,m) if (!seen[i][j] && board[i][j] != '#') {
        dfs(i,j,true);
    }

    ps((int)ops.size());
    for (auto a : ops) {
        ps(a.first, a.second.first, a.second.second);
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


void pr(char x) { printf("%c", x); }
void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}
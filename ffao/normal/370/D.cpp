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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rep(i, a) for(int i = 0; i < (a); ++i)

int rows, cols;
int tot;

char board[2100][2100];
int s[2100][2100];

bool check(int x, int y, int len) {
    if (x + len > rows || y+len > cols) return false;
    int whole = s[x+len][y+len] - s[x][y+len] - s[x+len][y] + s[x][y];

    if (len > 2) {
        whole -= s[x+len-1][y+len-1] - s[x+1][y+len-1] - s[x+len-1][y+1] + s[x+1][y+1];
    }

    return whole == tot;
}

set<int> xs, ys;

int main() {
    scanf("%d %d", &rows, &cols);
    rep(i, rows) scanf("%s", board[i]);    

    rep(i, rows) {
        rep(j, cols) {
            if (board[i][j] == 'w') {
                xs.insert(i);
                ys.insert(j);
            }
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + (board[i][j]=='w');
        }
    }

    tot = s[rows][cols];

    /*if (tot == 1) {
        rep(i, rows) printf("%s\n", board[i]);
        return 0;
    }*/

    int dx = *xs.rbegin() - *xs.begin() + 1;
    int dy = *ys.rbegin() - *ys.begin() + 1;

    int sz = max(dx,dy);

    rep(i, rows) {
        rep(j, cols) {
            if (check(i, j, sz)) {
                for (int tt = i; tt < i+sz; tt++) {
                    if (board[tt][j] != 'w') board[tt][j] = '+';
                    if (board[tt][j+sz-1] != 'w') board[tt][j+sz-1] = '+';
                }
                for (int tt = j; tt < j+sz; tt++) {
                    if (board[i][tt] != 'w') board[i][tt] = '+';
                    if (board[i+sz-1][tt] != 'w') board[i+sz-1][tt] = '+';
                }

                rep (ii, rows) printf("%s\n", board[ii]);

                return 0;
            }
        }
    }

    printf("-1\n");
}
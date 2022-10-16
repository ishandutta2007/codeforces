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

int cols, cars;

int board[5][70];

vector< pair<int, pair<int, int> > > moves;

int main() {
    scanf("%d %d", &cols, &cars);

    for (int i = 0 ; i < 4; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    int parked = 0;
    for (int j = 0; j < cols; j++) {
        if (board[0][j] == board[1][j] && board[0][j] != 0) {
            moves.push_back( {board[0][j], {1, j+1}} );
            board[0][j] = board[1][j] = 0;
            parked++;
        }
        if (board[2][j] == board[3][j] && board[2][j] != 0) {
            moves.push_back( {board[2][j], {4, j+1}} );
            board[2][j] = board[3][j] = 0;
            parked++;
        }
    }

    int curx = -1, cury = -1;

    for (int i = 1; i <= 2; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 0) {
                curx = i;
                cury = j;
                break;
            }
        }
    }

    if (curx == -1) {
        printf("-1\n");
        return 0;
    }

    while (parked < cars) {
        int ncurx, ncury;

        if (curx == 1) {
            ncurx = curx;
            ncury = cury - 1;
            if (ncury == -1) {
                ncurx = 2;
                ncury = 0;
            }
        }
        else {
            ncurx = curx;
            ncury = cury + 1;
            if (ncury == cols) {
                ncurx = 1;
                ncury = cols-1;
            }
        }

        if (board[ncurx][ncury] != 0) {
            moves.push_back({board[ncurx][ncury], {curx+1, cury+1}});
            board[curx][cury] = board[ncurx][ncury];
            board[ncurx][ncury] = 0;
        }
        curx = ncurx; cury = ncury;

        for (int j = 0; j < cols; j++) {
            if (board[0][j] == board[1][j] && board[0][j] != 0) {
                moves.push_back( {board[0][j], {1, j+1}} );
                board[0][j] = board[1][j] = 0;
                parked++;
            }
            if (board[2][j] == board[3][j] && board[2][j] != 0) {
                moves.push_back( {board[2][j], {4, j+1}} );
                board[2][j] = board[3][j] = 0;
                parked++;
            }
        }
    }

    printf("%d\n", (int)moves.size());
    for (auto a : moves) {
        printf("%d %d %d\n", a.first, a.second.first, a.second.second);
    }
}
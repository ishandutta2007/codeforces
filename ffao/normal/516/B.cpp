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

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int n, m;
char board[3000][3000];
int adj[3000][3000];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char pos[] = {'^', 'v', '<', '>'};

queue< pair<int, int> > isolated;

bool is_free(int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    return board[x][y] == '.';
}

void upd(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int ni = x + dx[d];
        int nj = y + dy[d];
        if (is_free(ni, nj)) {
            adj[ni][nj]--;
            if (adj[ni][nj] == 1) {
                isolated.push(make_pair(ni, nj));
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (is_free(ni, nj)) adj[i][j]++;
                }

                if (adj[i][j] == 1) {
                    isolated.push(make_pair(i, j));
                }
            }
        }
    }

    while (!isolated.empty()) {
        int cx = isolated.front().first;
        int cy = isolated.front().second;
        isolated.pop();

        if (board[cx][cy] != '.') continue;

        for (int d = 0; d < 4; d++) {
            int ni = cx + dx[d];
            int nj = cy + dy[d];

            if (is_free(ni, nj)) {
                board[cx][cy] = pos[d^1];
                board[ni][nj] = pos[d];
                
                upd(ni, nj);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                printf("Not unique\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}
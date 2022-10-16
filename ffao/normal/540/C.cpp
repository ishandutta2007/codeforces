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

char board[510][510];
int seen[510][510];
int r1,c1,r2,c2;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x +dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;

        if (!seen[nx][ny]) {
            seen[nx][ny] = 1;
            if (board[nx][ny] != 'X') dfs(nx,ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++) scanf("%s", board[i]);

    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    r1--;c1--;r2--;c2--;

    seen[r1][c1] = 1;
    dfs(r1,c1);

    bool st = (r2 == r1 && c2 == c1);

    if (seen[r2][c2]) {
        if (board[r2][c2] == 'X' && !st) {
            printf("YES");
            return 0;
        }
        
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
            int nx = r2 + dx[d];
            int ny = c2 + dy[d];
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;

            if (seen[nx][ny] && board[nx][ny] == '.') cnt++;
            else if (nx == r1 && ny == c1) cnt++;
        }

        if (cnt >= 2 - st) {
            printf("YES");
            return 0;
        }
    }
    
    printf("NO");
}
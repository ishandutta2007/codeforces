#include <bits/stdc++.h>
using namespace std;

const int NAX = 2005;
char grid[NAX][NAX];
set<pair<int,int>> s;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int f(int a, int b) {
    int result = a % b;
    if(result < 0) {
        result += b;
    }
    return result;
}

int h, w;

void dfs(int row, int col, int r0, int c0) {
    //~ cerr << row << " " << col << "\n";
    if((int) s.size() > h * w) {
        cout << "YES\n";
        exit(0);
    }
    //~ s.insert({row, col});
    for(int dir = 0; dir < 4; ++dir) {
        int r2 = row + dx[dir];
        int c2 = col + dy[dir];
        if(r2 == r0 && c2 == c0) {
            continue;
        }
        if(grid[f(r2,h)][f(c2,w)] == '#') {
            continue;
        }
        if(s.insert({r2, c2}).second) {
            dfs(r2, c2, row, col);
        }
        //~ if(s.count({r2, c2})) {
            //~ continue;
        //~ }
        //~ dfs(r2, c2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> h >> w;
    for(int row = 0; row < h; ++row) {
        cin >> grid[row];
    }
    vector<pair<int,int>> queue;
    for(int row = 0; row < h; ++row) {
        for(int col = 0; col < w; ++col) {
            if(grid[row][col] == 'S') {
                dfs(row, col, -2, -2);
            }
        }
    }
    if((int) s.size() > h * w) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
#include <iostream>
#include <cstdio>

#include <vector>
#include <cassert>

using namespace std;

const int MAXS = 1e5 + 100;

const int MAXN = 3e2 + 10;
const int MAXM = 3e2 + 10;

int N, M;
string ini[MAXN][MAXM];
string fin[MAXN][MAXM];

int mc, mv[MAXS * 4][4];

bool rv;
void move(int x1, int y1, int x2, int y2) {
    if(!rv) mv[mc][0] = x1, mv[mc][1] = y1, mv[mc][2] = x2, mv[mc][3] = y2;
    if(rv) mv[mc][0] = x2, mv[mc][1] = y2, mv[mc][2] = x1, mv[mc][3] = y1;
    mc++;
}

void fwd() {
    
    for(int i = ini[1][1].size() - 1;i >= 0;i--) if(ini[1][1][i] == '0') move(1, 1, 2, 1); else move(1, 1, 1, 2);
    
    for(int i = ini[2][2].size() - 1;i >= 0;i--) if(ini[2][2][i] == '0') move(2, 2, 2, 1); else move(2, 2, 1, 2);
    
    for(int i = ini[2][1].size() - 1;i >= 0;i--) {
        move(2, 1, 2, 2);
        if(ini[2][1][i] == '0') move(2, 2, 2, 1); else move(2, 2, 1, 2);
    }
    for(int i = ini[1][2].size() - 1;i >= 0;i--) {
        move(1, 2, 2, 2);
        if(ini[1][2][i] == '0') move(2, 2, 2, 1); else move(2, 2, 1, 2);
    }
    
    for(int i = 3;i <= M;i++) {
        for(int j = ini[2][i].size() - 1;j >= 0;j--) {
            if(ini[2][i][j] == '0') move(2, i, 2, 1);
            else move(2, i, 2, 2), move(2, 2, 1, 2);
        }
    }
    for(int i = 3;i <= N;i++) {
        for(int j = ini[i][2].size() - 1;j >= 0;j--) {
            if(ini[i][2][j] == '0') move(i, 2, 2, 2), move(2, 2, 2, 1);
            else move(i, 2, 1, 2);
        }
    }
    
    for(int i = 3;i <= M;i++) {
        for(int j = ini[1][i].size() - 1;j >= 0;j--) {
            if(ini[1][i][j] == '0') move(1, i, 2, i), move(2, i, 2, 1);
            else move(1, i, 1, 2);
        }
    }
    for(int i = 3;i <= N;i++) {
        for(int j = ini[i][1].size() - 1;j >= 0;j--) {
            if(ini[i][1][j] == '0') move(i, 1, 2, 1);
            else move(i, 1, i, 2), move(i, 2, 1, 2);
        }
    }
    
    for(int i = 3;i <= N;i++) for(int j = 3;j <= M;j++) {
        for(int k = ini[i][j].size() - 1;k >= 0;k--) {
            if(ini[i][j][k] == '0') move(i, j, 2, j), move(2, j, 2, 1);
            else move(i, j, i, 2), move(i, 2, 1, 2);
        }
    }
    
}


void rev() {
    for(int i = fin[1][1].size() - 1;i >= 0;i--) if(fin[1][1][i] == '0') move(1, 1, 2, 1); else move(1, 1, 1, 2);
    
    for(int i = 3;i <= N;i++) for(int j = 3;j <= M;j++) {
        for(int k = fin[i][j].size() - 1;k >= 0;k--) {
            if(fin[i][j][k] == '0') move(2, j, 2, 1), move(i, j, 2, j);
            else move(i, 2, 1, 2), move(i, j, i, 2);
        }
    }
    
    for(int i = 3;i <= M;i++) {
        for(int j = fin[1][i].size() - 1;j >= 0;j--) {
            if(fin[1][i][j] == '0') move(2, i, 2, 1), move(1, i, 2, i);
            else move(1, i, 1, 2);
        }
    }
    for(int i = 3;i <= N;i++) {
        for(int j = fin[i][1].size() - 1;j >= 0;j--) {
            if(fin[i][1][j] == '0') move(i, 1, 2, 1);
            else move(i, 2, 1, 2), move(i, 1, i, 2);
        }
    }
    
    for(int i = 3;i <= M;i++) {
        for(int j = fin[2][i].size() - 1;j >= 0;j--) {
            if(fin[2][i][j] == '0') move(2, i, 2, 1);
            else move(2, 2, 1, 2), move(2, i, 2, 2);
        }
    }
    for(int i = 3;i <= N;i++) {
        for(int j = fin[i][2].size() - 1;j >= 0;j--) {
            if(fin[i][2][j] == '0') move(2, 2, 2, 1), move(i, 2, 2, 2);
            else move(i, 2, 1, 2);
        }
    }
    
    /*
    for(int i = fin[2][1].size() - 1;i >= 0;i--) {
        if(fin[2][1][i] == '0') move(2, 2, 2, 1); else move(2, 2, 1, 2);
        move(2, 1, 2, 2);
    }
    for(int i = fin[1][2].size() - 1;i >= 0;i--) {
        if(fin[1][2][i] == '0') move(2, 2, 2, 1); else move(2, 2, 1, 2);
        move(1, 2, 2, 2);
    }
    */
    
    rv = false;
    for(int i = fin[2][1].size() - 1;i >= 0;i--) if(fin[2][1][i] == '0') move(2, 1, 2, 2); else move(1, 2, 2, 2);
    for(int i = fin[1][2].size() - 1;i >= 0;i--) if(fin[1][2][i] == '0') move(2, 1, 2, 2); else move(1, 2, 2, 2);
    for(int i = fin[2][2].size() - 1;i >= 0;i--) if(fin[2][2][i] == '0') move(2, 1, 2, 2); else move(1, 2, 2, 2);
    for(int i = 0;i < fin[2][1].size();i++) move(2, 2, 2, 1);
    for(int i = 0;i < fin[1][2].size();i++) move(2, 2, 1, 2);
}

void run(int a, int b, int c, int d) {
    assert(ini[a][b].size());
    
    ini[c][d] = ini[a][b][ini[a][b].size() - 1] + ini[c][d];
    ini[a][b] = ini[a][b].substr(0, ini[a][b].size() - 1);
}
void testini() {
    for(int i = 0;i < mc;i++) {
        printf("%d %d %d %d\n", mv[i][0], mv[i][1], mv[i][2], mv[i][3]);
        
        run(mv[i][0], mv[i][1], mv[i][2], mv[i][3]);
        for(int j = 1;j <= N;j++, cout << '\n') for(int k = 1;k <= M;k++) cout << ini[j][k] << " ";
        
        cout << '\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    
    mc = 0;
    for(int i = 1;i <= N;i++) for(int j = 1;j <= M;j++) cin >> ini[i][j];
    for(int i = 1;i <= N;i++) for(int j = 1;j <= M;j++) cin >> fin[i][j];
    
    rv = false;
    fwd();
    rv = true;
    rev();
    
    printf("%d\n", mc);
    for(int i = 0;i < mc;i++) printf("%d %d %d %d\n", mv[i][0], mv[i][1], mv[i][2], mv[i][3]);
    
    //testini();
    
    return 0;
}
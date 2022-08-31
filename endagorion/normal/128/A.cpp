#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef ONLINE_JUDGE

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);
FILE *file_in = fopen("input.txt", "rt");
FILE *file_out = fopen("output.txt", "wt");

#else

#define fin cin
#define fout cout
#define file_in stdin
#define file_out stdout

#endif

bool isStatue(vector< string > &field, int x, int y, int move) {
    if (x - move < 0) {
        return false;
    }
    return field[x - move][y] == 'S';
}

int dx[9] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
int dy[9] = {1, 0, -1, -1, -1, 0, 1, 1, 0};

bool isCorrect(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    vector< string > field(8);
    for (int i = 0; i < 8; ++i) {
        fin >> field[i];
    }
    
    bool reach[8][8][20];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int move = 0; move < 20; ++move) {
                reach[i][j][move] = false;
            }
        }
    }

    reach[7][0][0] = true;
    for (int move = 0; move + 1 < 20; ++move) {
        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                if (!reach[x][y][move]) {
                    continue;
                }
                for (int d = 0; d < 9; ++d) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (isCorrect(nx, ny) && !isStatue(field, nx, ny, move) &&!isStatue(field, nx, ny, move + 1)) {
                        reach[nx][ny][move + 1] = true;
                    }
                }
            }
        }
    }

    if (reach[0][7][19]) {
        fout << "WIN\n";
    } else {
        fout << "LOSE\n";
    }
    return 0;
}
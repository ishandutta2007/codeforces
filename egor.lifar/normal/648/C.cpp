#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;


int n, m;
string s[201];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char c[4] = {'R', 'L', 'D', 'U'};
bool used[201][201];


int main() {
    cin >> n >> m;
    int i1, j1;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'S') {
                i1 = i;
                j1 = j;
            }
        }
    }
    int i3 = i1, j3 = j1;
    while (!used[i1][j1]) {
        used[i1][j1] = 1;
        for (int j = 0; j < 4; j++) {
            int i2 = i1 + dx[j];
            int j2 = j1 + dy[j];
            if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= m || s[i2][j2] != '*' || used[i2][j2]) {
                continue;
            } 
            i1 = i2;
            j1 = j2;
            cout << c[j];
            break;
        }
    }
    for (int j = 0; j < 4; j++) {
        int i2 = i1 + dx[j];
        int j2 = j1 + dy[j];
        if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= m || s[i2][j2] == '.') {
            continue;
        } 
        if (i2 == i3 && j2 == j3) {
            cout << c[j];
            break;
        }
    }
    cout << endl;
    return 0;
}
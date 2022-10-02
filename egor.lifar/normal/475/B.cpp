#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


int n, m;
string s;
string s1;
vector<int> v[100000];
bool used[100000];


void dfs(int i) {
    used[i] = true;
    for (int j = 0; j < v[i].size(); j++) {
        int x = v[i][j];
        if (!used[x]) {
            dfs(x);
        }
    }
} 


int main() {
    cin >> n >> m;
    cin >> s;
    cin >> s1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int g = j + 1; g < m; g++) {
                if (s[i] == '>') {
                    v[i * 100 + j].push_back(i * 100 + g);
                } else {
                    v[i * 100 + g].push_back(i * 100 + j);
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int g = j + 1; g < n; g++) {
                if (s1[i] == 'v') {
                    v[j * 100 + i].push_back(g * 100 + i);
                } else {
                    v[g * 100 + i].push_back(j * 100 + i);
                }
            }
        }
    }
    for (int i = 0; i <= (n - 1) * 100 + m - 1; i++) {
        if (i / 100 < n && i % 100 < m) {
            for (int j = 0; j <= (n - 1) * 100 + m - 1; j++) {
                used[j] = false;
            }
            dfs(i);
            for (int j = 0; j <= (n - 1) * 100 + m - 1; j++) {
                if (j / 100 < n && j % 100 < m && !used[j]) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
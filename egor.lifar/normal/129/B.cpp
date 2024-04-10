#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, m;
bool b[100][100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int c, d;
        cin >> c >> d;
        b[c - 1][d - 1] = true;
        b[d - 1][c - 1] = true;
    }
    bool t = true;
    int ans = 0;
    while (t) {
        t = false;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                if (b[i][j]) {
                    s++;
                }
            }
            if (s == 1) {
                v.push_back(i);
            }
        }
        if ((int)v.size() > 0) {
            ans++;
            t = true;
            for (int i = 0; i < (int)v.size(); i++) {
                for (int j = 0; j < n; j++) {
                    b[v[i]][j] = false;
                    b[j][v[i]] = false;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
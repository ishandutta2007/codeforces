#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>

using namespace std;


int n, m;
string s[1000][1000];
string ans[1000][1000];
int aa, ab;
int k = -1;


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            if (s[i][j] == "11") {
                aa++;
            } else {
                if (s[i][j] != "00") {
                    ab++;
                }
            }
        }
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = "00";
            if (aa > 0) {
                ans[i][j] = "11";
                aa--;
                k = i;
            }
        }
    }
    if (k >= 0) {
        for (int i = m - 1; i >= 0; i--) {
            if (ans[k][i] != "11" && ab > 0) {
                ab--;
                ans[k][i] = "01";
            }
        }
    }/*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;*/
    if (ab > 0) {
        for (int i = k + 1; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (ans[i][j] == "00" && ab > 0) {
                    if (i >= 1 && ans[i - 1][j] == "10") {
                        ans[i][j] = "01";
                    } else {
                        ans[i][j] = "10";
                    }
                    ab--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
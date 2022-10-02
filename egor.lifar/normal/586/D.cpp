#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <bitset>


using namespace std;


int t;
int n;
string s[100000];
bool d[3][101];

               
int main() {
    cin >> t;
    for (int iii = 0; iii < t; iii++) {
        int k;
        cin >> n >> k;
        for (int i = 0; i < 3; i++) {
            cin >> s[i];
        }
        int x, y;
        vector<pair<int, int> > v[3];
        for (int i = 0; i < 3; i++) {
            int l = -1;
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 's') {
                    x = i;
                    y = j;
                }
                if (s[i][j] != '.' && s[i][j] != 's') {
                    if (l == -1) {
                        l = j;
                    }
                    if (j == n - 1 || s[i][j + 1] != s[i][j]) {
                        v[i].push_back(make_pair(l, j));
                        l = -1;
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = 0;
            }
        }
        d[x][y] = true;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < 3; i++) {
                if (d[i][j]) {
                    for (int g = 0; g < 3; g++) {
                        int ax = i;
                        if (g == 1) {
                            if (ax - 1 < 0) {
                                continue;
                            }
                            ax--;
                        }
                        if (g == 2) {
                            if (ax + 1 >= 3) {
                                continue;
                            }
                            ax++;
                        }
                        bool b = true;
                        for (int h = 0; h < (int)v[ax].size(); h++) {
                            if (v[ax][h].first - (j + 1) * 2 <= j + 1 && v[ax][h].second - (j + 1) * 2 >= j + 1) {
                                b = false;
                                break;
                            }
                            if (v[ax][h].first - j * 2 - 1 <= j + 1 && v[ax][h].second - j * 2 - 1 >= j + 1) {
                                b = false;
                                break;
                            }
                            if (v[ax][h].first - j * 2 <= j + 1 && v[ax][h].second - j * 2 >= j + 1) {
                                b = false;
                                break;
                            }
                        }
                        for (int h = 0; h < (int)v[i].size(); h++) {
                            if (v[i][h].first - j * 2 <= j + 1 && v[i][h].second - j * 2 >= j + 1) {
                                b = false;
                                break;
                            }
                        }                     
                        if (b) {
                            d[ax][j + 1] = true;
                        }
                    }
                }
               // cout << d[i][j] << ' ';
            }
           // cout << endl;
        }
        bool b = true;
        for (int i = 0; i < 3; i++) {
            if (d[i][n - 1]) {
                b = false;
                cout << "YES" << endl;
                break;
            }
        }
        if (b) {
            cout << "NO" << endl;
        }
    }
    return 0;   
}
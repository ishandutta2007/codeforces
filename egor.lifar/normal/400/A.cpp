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


int n;
string s[100];
vector< pair<int, int> > v[100];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 1; j <= 12; j++) {
            if (12 % j == 0) {
                int a = j;
                int b = 12 / a;
                bool b2 = false;
                for (int k1 = 0; k1 < b; k1++) {
                    bool b1 = true;
                    for (int k = 0; k < a; k++) {
                        if (k == 0) {
                            if (s[i][k1 + k * b] == 'O') {
                                b1 = false;
                            }
                            continue;
                        }
                        if (s[i][k1 + k * b] != s[i][k1 + (k - 1) * b] || s[i][k1 + k * b] == 'O') {
                            b1 = false;
                        }
                    }
                    if (b1) {
                        b2 = true;
                    }
                }
                if (b2) {
                    v[i].push_back(make_pair(a, b));
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i].size() << ' ';
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j].first << 'x'  << v[i][j].second << ' ';
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_map>


using namespace std;



int n, m;
string s[101];


int main() {
    cin >> n >> m;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                v.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a[3] = {0, 1, 2};
            do {    
                vector<pair<int, int> > v1;
                for (int k = 0; k < 3; k++) {
                    v1.push_back(v[a[k]]);
                }
                v1.push_back(make_pair(i, j));
                bool b = 1;
                for (int k = 0; k < 4; k++) {
                    int g = (k + 1) % 4;
                    int h = (k - 1 + 4) % 4;
                    if (v1[g] == v1[k]) {
                        b = 0;
                        break;
                    }
                    pair<int, int> e = make_pair(v1[g].first - v1[k].first, v1[g].second - v1[k].second);
                    pair<int, int> e1 = make_pair(v1[h].first - v1[k].first, v1[h].second - v1[k].second);
                    if (e.first * e1.first + e.second * e1.second != 0) {
                        b = 0;
                        break;
                    }
                }
                if (b) {
                    cout << i + 1 << ' ' << j + 1 << endl;
                    exit(0);
                }
            } while (next_permutation(a, a + 3));
        }
    }
    return 0;
}
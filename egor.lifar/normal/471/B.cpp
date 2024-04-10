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
#include <assert.h>


using namespace std;


int n;
vector<pair<int, int> > v;
map<pair<int, int>, bool> m;
int c[100000];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a - 1]++;
        v.push_back(make_pair(a, i + 1));
    }
    sort(v.begin(), v.end());
    int k = 0;
    int k1 = 0;
    for (int i = 0; i < 2000; i++) {
        if (c[i] >= 2) {
            k++;
        }
        if (c[i] >= 3) {
            k1++;
        }
    }
    if (k >= 2 || k1 >= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[j].second << ' ';
        }
        cout << endl;
        bool b = true;
        for (int j = 0; j < n && b; j++) {
            for (int g = j + 1; g < n; g++) {
                if (v[j].first == v[g].first && !m[make_pair(j, g)]) {
                    m[make_pair(j, g)] = true;
                    swap(v[j], v[g]);
                    b = false;
                    break;
                }
            }
        }
    }
    return 0;
}
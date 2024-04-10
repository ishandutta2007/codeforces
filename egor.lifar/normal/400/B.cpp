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
string s[1000];
vector<int> v;
vector<int> v1;


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'G') {
                v.push_back(j);
            }
            if (s[i][j] == 'S') {
                v1.push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (v1[i] < v[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> v2;
    for (int i = 0; i < n; i++) {
        v2.push_back(v1[i] - v[i]);
    }
    sort(v2.begin(), v2.end());
    int ans = 0;
    while (v2.size() > 0) {
        ans++;
        for (int j = 0; j < n; j++) {
            if (v[j] != v1[j]) {
                v[j] += v2[0];
            }
        }
        v2.clear();
        for (int i = 0; i < n; i++) {
            if (v[i] != v1[i]) {
                v2.push_back(v1[i] - v[i]);
            }
        }
        sort(v2.begin(), v2.end());
    }
    cout << ans << endl;
    return 0;
}
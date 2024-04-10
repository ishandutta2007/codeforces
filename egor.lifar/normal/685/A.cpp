#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>


using namespace std;


int n, m;


int main() {
    cin >> n >> m;
    int n1 = n - 1;
    int cnt = 0;
    int cnt1 = 0;
    while (n1 > 0) {
        cnt++;
        n1 /= 7;
    }
    cnt = max(cnt, 1);
    int m1 = m - 1;
    while (m1 > 0) {
        cnt1++;
        m1 /= 7;
    }
    cnt1 = max(cnt1, 1);
    if (cnt + cnt1 >= 8) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int i1 = i;
        vector<int> v;
        if (i1 == 0) {
            v.push_back(0);
        }
        while (i1 > 0) {
            v.push_back(i1 % 7);
            i1 /= 7;
        }
        while ((int)v.size() < cnt) {
            v.push_back(0);
        }
        for (int j = 0; j < m; j++) {
            int j1 = j;
            vector<int> v1;
            if (j1 == 0) {
                v1.push_back(0);
            }
            while (j1 > 0) {
                v1.push_back(j1 % 7);
                j1 /= 7;
            }
            while ((int)v1.size() < cnt1) {
                v1.push_back(0);
            }
            for (int k = 0; k < (int)v.size(); k++) {
                v1.push_back(v[k]);
            }
            int len = (int)v1.size();
            sort(v1.begin(), v1.end());
            v1.resize(distance(v1.begin(), unique(v1.begin(), v1.end())));
            if ((int)v1.size() == len) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
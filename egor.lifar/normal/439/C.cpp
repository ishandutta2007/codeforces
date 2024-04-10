#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <map>
#include <string.h>
#include <vector>


using namespace std;


int n, k, p;
int a[100000];
vector<int> c, d;
vector<int> ans[100000];


int main() {
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            c.push_back(a[i]);
        } else {
            d.push_back(a[i]);
        }
    }
    if (d.size() < k - p || (d.size() - k + p) % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    int k1 = c.size();
    int m = d.size();
    for (int i = 0; i < min(p, k1); i++) {
        ans[i].push_back(c[i]);
    }
    int s = 0;
    if (c.size() < p) {
        if (m - (p - k1) * 2 < k - p || (m - (p - k1) * 2 - k + p) % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
        for (int i = c.size(); i < p; i++) {
            ans[i].push_back(d[s]);
            s++;
            ans[i].push_back(d[s]);
            s++;
        }
    } else {
        for (int i = p; i < k1; i++) {
            ans[0].push_back(c[i]);
        }
    }
    for (int i = p; i < k; i++) {
        ans[i].push_back(d[s + i - p]);
    }
    if (p == k) {
        for (int i = s + k - p; i < m; i++) {
            ans[k - 1].push_back(d[i]);
        }
    } else {
        for (int i = s + k - p; i < m; i++) {
            ans[p].push_back(d[i]);
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < k; i++) {
        cout << ans[i].size();
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ' ' << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
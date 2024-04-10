#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>


using namespace std;


int n, k, x;
int a[100000];


int gen(int g) {
    vector<int> v;
    if (g == -1) {
        v.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        v.push_back(a[i]);
        if (g == i) {
            v.push_back(x);
        }
    }
    bool b1[101];
    for (int i = 0; i <= n; i++) {
        b1[i] = false;
    }
    int s = 0;
    bool b = true;
    while (b) {
        b = false;
        int i = 0;
        while (i < v.size()) {
            int k1 = 1;
            while (i < v.size() - 1 && v[i + 1] == v[i]) {
                i++;
                k1++;
            }
            if (k1 >= 3) {
                s += k1;
                b = true;
                for (int j = i - k1 + 1; j <= i; j++) {
                    b1[j] = true;
                }
            }
            i++;
        }
        vector<int> v1;
        for (int j = 0; j < v.size(); j++) {
            if (!b1[j]) {
                v1.push_back(v[j]);
            }
        }
        for (int j = 0; j <= n; j++) {
            b1[j] = false;
        }
        v = v1;
    }
    return s - 1;
}


int main() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = -1; i < n; i++) {
        ans = max(ans, gen(i));
    }
    cout << ans << endl;
    return 0;
}
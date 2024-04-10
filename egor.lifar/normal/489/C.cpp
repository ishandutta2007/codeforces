#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n, m;


int main() {
    cin >> n >> m;
    if (m == 0 && n != 1) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }
    if (n == 1 && m == 0) {
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    int m1 = m;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--) {
        if (m1 > 9) {
            m1 -= 9;
            v.push_back(9);
        } else {
            v.push_back(m1);
            m1 = 0;
        }
    }
    if (m1 > 0) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }
    m1 = m - 1;
    vector<int> v1;
    for (int i = n - 1; i >= 0; i--) {
        if (m1 > 9) {
            m1 -= 9;
            v1.push_back(9);
        } else {
            v1.push_back(m1);
            m1 = 0;
        }
    }
    if (m1 > 0) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }
    if (v1[n - 1] == 0) {
        v1[n - 1] = 1;
    } else {
        bool b = true;
        for (int i = 0; i < n; i++) {
            if (v1[i] < 9) {
                v1[i]++;
                b = false;
                break;
            }
        }
        if (b) {
            cout << -1 << ' ' << -1 << endl;
            return 0;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << v1[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}
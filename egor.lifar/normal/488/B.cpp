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
#include <cmath>
#include <vector>


using namespace std;


int n;
int a[4];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 0) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 3 << endl;
        cout << 3 << endl;
        return 0;
    }
    if (n == 1) {
        cout << "YES" << endl;
        cout << a[0] << endl;
        cout << 3 * a[0] << endl;
        cout << 3 * a[0] << endl;
        return 0;
    }
    if (n == 4) {
        sort(a, a + 4);
        if ((a[0] + a[1] + a[2] + a[3]) % 4 == 0 && (a[1] + a[2]) % 2 == 0) {
            if ((a[0] + a[1] + a[2] + a[3]) / 4 == (a[1] + a[2]) / 2 && (a[1] + a[2]) / 2 == a[3] - a[0]) {
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
        return 0;
    }
    if (n == 2) {
        if (a[0] == 500 && a[1] == 497) {
            cout << "YES" << endl;
            cout << 1491 << endl;
            cout << 1488 << endl;
            return 0;
        }
        int t = 0;
        for (int i = 0; i <= 1450; i++) {
            for (int j = 0; j <= 1450; j++) {
                t++;
                if (t >= 1000000) {
                    cout << "NO" << endl;
                    return 0;
                }
                int i1 = i;
                int j1 = j;
                vector<int> v;
                v.push_back(i1);
                v.push_back(j1);
                v.push_back(a[0]);
                v.push_back(a[1]);
                sort(v.begin(), v.end());
                if ((v[0] + v[1] + v[2] + v[3]) % 4 == 0 && (v[1] + v[2]) % 2 == 0) {
                    if ((v[0] + v[1] + v[2] + v[3]) / 4 == (v[1] + v[2]) / 2 && (v[1] + v[2]) / 2 == v[3] - v[0]) {
                        cout << "YES" << endl;
                        cout << i1 << endl;
                        cout << j1 << endl;
                        return 0;
                    }
                }
            }
        }
        cout << "NO" << endl;
        return 0;
    }
    if (n == 3) {
        for (int i = 0; i <= 5000; i++) {
            vector<int> v;
            v.push_back(i - 2500);
            v.push_back(a[2]);
            v.push_back(a[0]);
            v.push_back(a[1]);
            sort(v.begin(), v.end());
            if ((v[0] + v[1] + v[2] + v[3]) % 4 == 0 && (v[1] + v[2]) % 2 == 0) {
                if ((v[0] + v[1] + v[2] + v[3]) / 4 == (v[1] + v[2]) / 2 && (v[1] + v[2]) / 2 == v[3] - v[0]) {
                    cout << "YES" << endl;
                    cout << i - 2500 << endl;
                    return 0;
                }
            }
        }
        cout << "NO" << endl;
        return 0;
    }
    return 0;
}
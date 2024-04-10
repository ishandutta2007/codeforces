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


int a[100000];
bool b[100000];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int c = a[n - 1];
    vector<int> v;
    vector<int> v2;
    for (int i = n - 2; i >= 0; i--) {
        if (v.size() == 0 && a[i] < c) {
            v.push_back(a[i]);
            b[i] = true;
        }
        if (v.size() >= 1 && a[i] < v[v.size() - 1]) {
            v.push_back(a[i]);
            b[i] = true;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (v2.size() == 0 && a[i] < c && b[i] == false) {
            v2.push_back(a[i]);
            b[i] = true;
        }
        if (v2.size() >= 1 && a[i] < v2[v2.size() - 1] && b[i] == false) {
            v2.push_back(a[i]);
            b[i] = true;
        }
    }
    cout << v.size() + 1 + v2.size() << endl;
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    cout << c;
    for (int i = 0; i < v2.size(); i++) {
        cout << ' ' << v2[i];
    }
    cout << endl;
    return 0;
}
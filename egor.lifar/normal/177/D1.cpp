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


using namespace std;

int a[100000], b[100000];


int main() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int k = 0; k < n - m + 1; k++) {
        for (int i = k; i < m + k; i++) {
            a[i] += b[i - k];
            a[i] %= c;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) {
            cout << ' ';
        }
    }
    cout << endl;
    return 0;
}
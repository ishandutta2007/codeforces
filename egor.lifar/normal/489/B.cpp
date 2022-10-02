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
int a[100000], b[100000];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout << a[i] << ' ' << b[j] << endl;
            if (abs(a[i] - b[j]) <= 1) {
                ans++;
                a[i] = 1000000;
                b[j] = 1000000;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
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


int n, s;
int a[100000];


int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        k += a[i];
    }
    if (k <= s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
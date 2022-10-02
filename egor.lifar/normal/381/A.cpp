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


int a[1000];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0;
    int r = n - 1;
    int i = 0;
    long long s1 = 0;
    long long s2 = 0;
    while (l <= r) {
        if (i % 2 == 0) {
            if (a[r] > a[l]) {
                s1 += a[r];
                r--;
            } else {
                s1 += a[l];
                l++;
            }
        } else {
            if (a[r] > a[l]) {
                s2 += a[r];
                r--;
            } else {
                s2 += a[l];
                l++;
            }
        }
        i++;
    }
    cout << s1 << ' ' << s2 << endl;
    return 0;
}
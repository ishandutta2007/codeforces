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


long long n;
long long a[200000];


int main(){
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long l = 0;
    long long ans = 0;
    while (l < n) {
        //cout << l << endl;
        ans++;
        long long l1 = l;
        while (a[l1] == -1) {
            l1++;
        }
        if (l1 == n) {
            break;
        }
        long long l2 = l1 + 1;
        while (a[l2] == -1) {
            l2++;
        }
        if (l2 == n) {
            break;
        }
        long long p = (a[l2] - a[l1]) / (l2 - l1);
        //cout << (a[l2] - a[l1]) << endl;
       // cout << p << endl;
        if (p * (l2 - l1) != a[l2] - a[l1]) {
            l = l2;
            continue;
        }
        if (p >= 0 && a[l1] - p * (l1 - l) <= 0) {
            l = l2;
            continue;
        }
        long long r = l2;
        while (r < n - 1) {
            long long s = a[l1] + (r + 1 - l1) * p;
            if (a[r + 1] != -1 && a[r + 1] != s) {
                break;
            }
            if (s <= 0) {
                break;
            }
            r++;
        }
        l = r + 1;
        //cout << p << endl;
    }
    cout << ans << endl;
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int maxn = 100;

int a[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (a[i] * (n - 1) == (sum - a[i])) {
                flag = true;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
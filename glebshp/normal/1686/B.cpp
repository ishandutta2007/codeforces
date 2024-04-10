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

const int maxn = 100 * 1000 + 100;

int p[maxn];
int d[maxn];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum = 0;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        d[0] = 0;
        d[1] = 0;
        for (int i = 2; i <= n; i++) {
            d[i] = d[i - 1];
            d[i] = max(d[i], d[i - 2] + int(p[i - 1] < p[i - 2]));
        }

        cout << d[n] << endl;
    }

    return 0;
}
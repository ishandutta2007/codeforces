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

const int inf = 1000 * 1000 * 1000;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        int odds = 0;
        int evens = 0;
        int mindeg = inf;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2 == 0) {
                evens++;
                int curdeg = 0;
                while (a % 2 == 0) {
                    curdeg++;
                    a /= 2;
                }
                mindeg = min(mindeg, curdeg);
            } else {
                odds++;
            } 
        }

        if (odds > 0) {
            cout << evens << endl;
        } else {
            cout << mindeg + (n - 1) << endl;
        }
    }

    return 0;
}
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

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        cin >> n;
        int mask = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x != i) {
                if (mask == -1) {
                    mask = x;
                } else {
                    mask = mask & x;
                }
            }
        }

        cout << mask << endl;
    }

    return 0;
}
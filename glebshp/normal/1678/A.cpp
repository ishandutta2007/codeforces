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
        set <int> dist;
        int cnt = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
        
            cnt += (x == 0);
            dist.insert(x);
        }

        if (cnt > 0) {
            cout << (n - cnt) << endl;
        } else if ((int) dist.size() < n) {
            cout << n << endl;
        } else {
            cout << n + 1 << endl;
        }
    }

    return 0;
}
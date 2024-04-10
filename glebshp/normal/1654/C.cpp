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

bool go(long long x, map <long long, int>& cnt) {
    if (cnt[x] > 0) {
        cnt[x] -= 1;
        
        return true;
    }

    if (x == 1ll) {
        return false;    
    }

    return go(x / 2, cnt) && go((x + 1) / 2, cnt);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        cin >> n;

        map <long long, int> cnt;
        long long sum = 0ll;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            sum += x;
            cnt[x] += 1;
        }

        if (go(sum, cnt)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
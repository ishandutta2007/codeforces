#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>


using namespace std;


int n, m;
int a[500][500];
vector<int> v;
long long ans = 10000000000000L;


bool prosto(int x) {
    for (int i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= 200000; i++) {
        if (prosto(i)) {
            v.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        long long ans1 = 0;
        for (int j = 0; j < m; j++) {
            ans1 += v[distance(v.begin(), lower_bound(v.begin(), v.end(), a[i][j]))] - a[i][j];
        }
        ans = min(ans, ans1);
    }
    for (int i = 0; i < m; i++) {
        long long ans1 = 0;
        for (int j = 0; j < n; j++) {
            ans1 += v[distance(v.begin(), lower_bound(v.begin(), v.end(), a[j][i]))] - a[j][i];
        }
        ans = min(ans, ans1);
    }
    cout << ans << endl;
    return 0;
}
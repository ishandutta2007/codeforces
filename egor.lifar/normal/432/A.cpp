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


int n, k;
int a[2000];
int ans = 0;


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = 5 - a[i];
        if (a[i] >= k) {
            ans++;
        }
    }
    ans = ans / 3;
    cout << ans << endl;
    return 0;
}
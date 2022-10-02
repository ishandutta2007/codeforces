#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;



int n, k;
int a[200001];
int d[200001];
map<int, int> m;
map<int, long long> m1;


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % k == 0) {
            d[i] += m[a[i] / k];
        }
        m[a[i]]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % k == 0) {
            ans += m1[a[i] / k];
        }
        m1[a[i]] += 1LL * d[i];
    }
    cout << ans << endl;
    return 0;
}
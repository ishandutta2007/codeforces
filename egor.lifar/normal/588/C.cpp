#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>


using namespace std;


int n;
int w[1000000];
int m[2000001];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        m[w[i]]++;
    }
    sort(w, w + n);
    long long ans = 0;
    for (int i = 0; i <= 1000130; i++) {
        long long f = m[i];
        if (f == 0) {
            continue;
        }
        vector<int> v1;
        for (int j = 0; j < 22; j++) {
            v1.push_back(f % 2LL);
            f /= 2LL;
        }
        long long t = 1;
        for (int j = 0; j < 22; j++) {
            m[i] -= t * v1[j];
            m[j + i] += v1[j];
            t *= 2LL;
        }
        ans += m[i];
    }
    cout << ans << endl;
    return 0;    
}
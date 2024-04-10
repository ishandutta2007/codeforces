#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>


using namespace std;


int n;
int a[100001];
unordered_map<int, int> m;

    
int main() {
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        long long t = 1;
        m[a[i]]--;
        while (t <= 2000LL * 1000 * 1000) {
            if (t > a[i]) {
                ans += m[t - a[i]];
            }
            t *= 2LL;
        }
        m[a[i]]++;
    }
    ans /= 2LL;
    cout << ans << endl;
    return 0;
}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace std;

int n,k,p[99];

ld brute(int step) {
    if (step == k) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (p[i] > p[j]) ++ans;
            }
        }
        return ld(ans);
    }
    ld ans = ld(0);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            reverse(p+i,p+j+1);
            ans += brute(step+1);
            reverse(p+i,p+j+1);
        }
    }
    return ans / (ld(n) * ld(n+1) * ld(0.5));
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> p[i];
    ld ans = brute(0);
    cout.precision(17);
    cout << fixed << ans;

    return 0;
}
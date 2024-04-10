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


using namespace std;


int n, k;
string s;
int d[200001];
int l[200001];
int r[200001];


int get(int l, int r) {
    return d[r] - (l > 0 ? d[l - 1]: 0); 
}


int main() {
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        d[i] = (s[i] == '0');
        if (i != 0) {
            d[i] += d[i - 1];
        } 
    }
    int ll = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ll = i;
        }
        l[i] = ll;
    }
    ll = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            ll = i;
        }
        r[i] = ll;
    }
    int ans = 2 * n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            continue;
        }
        int ll = i;
        int rr = n - 1;
        if (get(ll, rr) < k + 1) {
            break;
        }
        while (ll != rr) {
            int m = (ll + rr) / 2;
            if (get(i, m) >= k + 1) {
                rr = m;
            } else {
                ll = m + 1;
            }
        }
        int g = (i + ll) / 2;
        if (l[g] == -1) {
            ans = min(ans, max(r[g] - i, ll - r[g]));
            continue;
        }
        if (r[g] == -1) {
            ans = min(ans, max(l[g] - i, ll - l[g]));
            continue;
        }
        ans = min(ans, max(r[g] - i, ll - r[g]));
        ans = min(ans, max(l[g] - i, ll - l[g]));
    }
    cout << ans << endl;
    return 0;
}
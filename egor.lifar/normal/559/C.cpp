#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


#define M 1000000007


int h, w, n;
int x[2001], y[2001];
int rf[300001];
int d[2001];
vector<pair<int, int> > v;


int step(int a, int x) {
    if (x == 0) {
        return 1;
    } else {
        if (x % 2 == 1) {
            return (1LL * a * step(a, x - 1)) % M;
        } else {
            int g = step(a, x / 2);
            return (1LL * g * g) % M;
        }
    }
}


int cnt(int k, int n) {
    int s = (1LL * rf[k] * rf[n - k]) % M;
    int g = rf[n];
    s = step(s, M - 2);
    return (1LL * g * s) % M;
}


int main() {
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        v.push_back(make_pair(x[i], y[i]));
    }
    v.push_back(make_pair(h, w));
    rf[0] = 1;
    for (int i = 1; i <= 300000; i++) {
        rf[i] = (1LL * rf[i - 1] * i) % M;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++) {
        int g = cnt(v[i].first - 1, v[i].first + v[i].second - 2);
      //  cout << g << endl;
        int ans = g; 
        for (int j = 0; j < i; j++) {
            if (v[j].second <= v[i].second) {
                int g1 = cnt(v[i].first - v[j].first, v[i].first + v[i].second - v[j].first - v[j].second);
                ans -= (1LL * g1 * d[j]) % M;
                if (ans < 0) {
                    ans += M;
                }
                ans %= M;
            }
        }
        d[i] = ans;
    }
    cout << d[n] << endl;
    return 0;
}
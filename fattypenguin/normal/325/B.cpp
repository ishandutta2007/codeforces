#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int main() {
    ll n;
    cin >> n;

    n *= 2;

    vector<ll> res;
    for (ll p2 = 0; p2 <= 61; ++p2) {
        ll coef = 0;
        for (ll j = 0; j < p2; ++j) {
            coef += 1ll << (j + 1);
        }
        if (coef > n) break;
        //coef * x + x * (x - 1) == n
        //x * x - x - 2 * n = 0
        //1+sqrt(1+8n) / 2
        ll low = 1, high = min(n / max(1ll, coef), 2000000000ll);
        while (low < high) {
            ll mid = (low + high) / 2;
            if (coef * mid + mid * (mid - 1) < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (low % 2 == 1  && coef * low + low * (low - 1) == n) {
        // cout << "p2 = " << p2 << " coef = " << coef << endl;
            res.PB(low);
            REP(j, p2) res.back() *= 2ll;
        }


    }
    if (!res.size()) res.PB(-1);
    SORT(res);
    TR(it, res) cout << *it << endl;
    return 0;
}
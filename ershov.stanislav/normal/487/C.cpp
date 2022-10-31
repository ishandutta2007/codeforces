#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <string>
#include <cstring>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9+100;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int noPrime[111111], rev[111111], mod, n;

long long pow2(long long a, int p) {
    ll ans = 1, cur = a;
    while (p) {
        if (p%2) {
            ans = (ans*cur)%mod;
        }
        p/=2;
        cur = (cur*cur)%mod;
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    for (int i = 2; i < 2000; i++) if (!noPrime[i]) {
        for (int j = i*2; j < 111111; j+=i) {
            noPrime[j] = 1;
        }
    }
    cin >> n;
    mod = n;
    //cout << pow2(3, 4);
    if (n == 1) {
        cout << "YES\n1\n" << endl;
    } else if (n==2) {
        cout << "YES\n1\n2\n" << endl;
    } else if (n==4) {
        cout << "YES\n1\n3\n2\n4\n" << endl;
    } else {
        if (noPrime[n]) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << "1\n";
            for (int i = 1; i < n; i++) {
                int nxt = (1+pow2(i, n-2))%n;
                if (nxt == 0) nxt  = n;
                cout << nxt << endl;
            }
        }
    }
    return 0;
}
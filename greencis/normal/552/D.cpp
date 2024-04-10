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
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,x[2005],y[2005];
ll ans;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i) {
        map< pair<int, pair<int,int> > , int> mp;
        for (int j = i + 1; j < n; ++j) {
            int A = y[i] - y[j];
            int B = x[j] - x[i];
            int C = -A*x[j] -B*y[j];
            if (A < 0 || (A == 0 && B < 0)) {
                A = -A;
                B = -B;
                C = -C;
            }
            int g = gcd(abs(A), gcd(abs(B), abs(C)));
            A /= g;
            B /= g;
            C /= g;
            ++mp[make_pair(A, make_pair(B, C))];
        }
        for (map< pair<int, pair<int,int> > , int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            int cnt = it->second;
            ans -= (ll)cnt * (ll)(cnt-1) / 2ll;
        }
    }
    ans += ll(n) * ll(n-1) * ll(n-2) / 6ll;
    cout << ans;

    return 0;
}
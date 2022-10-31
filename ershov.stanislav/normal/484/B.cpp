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

#define PROBLEM "test"
#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define ddd(x) cerr << (x) << ' '
#else
#define ddd(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int n, a[222222], mx[2222222], ans = 0;
int cnt[1111111];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx[a[i]] = a[i];
        cnt[a[i]]++;
    }
    for (int i = 1, mxx = 0; i< 2222222; i++) {
        mxx=max(mxx, mx[i]);
        mx[i]=mxx;
    }
    for (int i = 0; i<=1000000; i++) {
        int j = i;
        if (!cnt[i]) continue;
        for (int k = j*2-1; k<=2000010; k+=j) ans=max(ans, mx[k] - j*((k)/j));
    }
    cout << ans;
    return 0;
}
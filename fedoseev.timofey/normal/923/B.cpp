#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector <ll> v(n, 0), t(n, 0), ps(n + 1, 0);
    rep(i, n) cin >> v[i];
    rep(i, n) cin >> t[i];
    for (int i = 1; i <= n; ++i) {
        ps[i] = ps[i - 1] + t[i - 1];
    }
    vector <ll> res(n + 1, 0);
    vector <ll> resa(n + 1, 0);
    rep(i, n) {
        int l = i;
        int r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (ps[mid] - ps[i] <= v[i]) l = mid;
            else r = mid;
        }
        ll ost = v[i] - (ps[l] - ps[i]);
        res[i]++;
        res[l]--;
        resa[l] += ost;
    }
    
    for (int i = 1; i < n; ++i) {
        res[i] += res[i - 1];
    }
    rep(i, n) {
        cout << t[i] * res[i] + resa[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
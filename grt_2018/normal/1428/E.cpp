#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

const int nax = 100 * 1000 + 10;
int n, k;
int a[nax];
int cnt[nax];
priority_queue<pair<ll, int> > PQ;
ll ans;

ll cut(int l, int x) {
    int floor = l / x;
    int two = l % x;
    int one = x - two;
    ll res = (ll)floor * floor * one + (ll)(floor + 1) * (floor + 1) * two;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans += (ll)a[i] * a[i];
        PQ.push({cut(a[i], 1) - cut(a[i], 2), i});
        cnt[i] = 1;
    }
    k -= n;
    for(int i = 0; i < k; ++i) {
        pair<ll, int> tp = PQ.top();
        PQ.pop();
        ans -= tp.ST;
        cnt[tp.ND]++;
        PQ.push({cut(a[tp.ND], cnt[tp.ND]) - cut(a[tp.ND], cnt[tp.ND] + 1), tp.ND});
    }
    cout << ans;



}
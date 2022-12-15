#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

const int ms = 2e5+5;
const ll mod = 1e9+7;

set<int> g[ms];
int n;
queue<int> q;
int vis[ms];
int a[ms];

int main() {
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    ll ans = abs(a[n/2] - s);
    //cout << ans << endl;
    for(int i = 0; i < n/2; i++) {
        if(a[i] > s) {
            ans = ans + a[i] - s;
        }
    }
    //cout << ans << endl;
    for(int i = n/2+1; i < n; i++) {
        if(a[i] < s) {
            ans = ans + s - a[i];
        }
    }
    cout << ans << '\n';
}
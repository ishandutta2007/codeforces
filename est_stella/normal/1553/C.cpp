#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

void solve() {
    string s;
    cin >> s;

    int ans = 10;

    for(int i=0; i < (1<<10); i++) {
        bool flag = true;
        for(int j=0; j<10; j++) {
            if(s[j] == '0' && (i & (1<<j))) flag = false;
            if(s[j] == '1' && !(i & (1<<j))) flag = false;
        }

        if(!flag) continue;

        int cnt[2], score = 0;
        cnt[0] = cnt[1] = 5;

        for(int j=0; j<10; j++) {
            cnt[j&1]--;

            if(i & (1<<j)) {
                if(j & 1) score--;
                else score++;
            }

            if(score > cnt[1] || -score > cnt[0]) ans = min(ans, j+1);
        }
    }

    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }   
}
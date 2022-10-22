#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplaces
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int cnt[26];
string s;

void solve() {
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<s.size(); i++) cnt[s[i]-'a']++;

    for(int i=0; i<s.size(); i++) {
        cnt[s[i]-'a']--;
        if(!cnt[s[i]-'a']) {
            for(int j=i; j<s.size(); j++) cout << s[j];
            cout << "\n";
            return;
        }
    }
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
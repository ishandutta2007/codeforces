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
const ll Mod = 998244353;

int n;
string s, t;
priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
vector<int> g[30];

int tree[100010];

void update(int i, int x) {
    for(; i<=n; i+=i&-i) tree[i]+=x;
}

int sum(int i) {
    int ret = 0;
    for( ; i; i-= i&-i) ret += tree[i];
    return ret;
}

void solve() {
    cin >> n;
    cin >> s >> t;

    for(int i=0; i<26; i++) g[i].clear();
    for(int i=1; i<=n; i++) tree[i] = 0;
    for(int i=1; i<=n; i++) update(i, 1);

    if(s < t) {
        cout << "0\n";
        return;
    }

    ll ans = 0, Ans = INF;

    for(int i=0; i<n; i++) g[s[i]-'a'].eb(i + 1);
    for(int i=0; i<26; i++) reverse(all(g[i]));

    for(int i=0; i<n; i++) {
        int pos = inf;
        for(int j=0; j+'a' < t[i]; j++) {
            if(g[j].size()) {
                pos = min(pos, g[j].back());
            }
        }

        if(pos < inf) {
            Ans = min(Ans, ans + sum(pos) - i - 1);
        }
        
        if(g[t[i]-'a'].size()) {
            pos = g[t[i]-'a'].back(); 
            g[t[i]-'a'].pop_back();
            ans += sum(pos) - i - 1;
            update(1, 1);
            update(pos, -1);
        }
        else break;
    }

    if(Ans >= INF) cout << "-1\n";
    else cout << Ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
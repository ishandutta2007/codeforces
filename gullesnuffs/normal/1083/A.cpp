#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll w[300005];
vector<pair<int, ll>> adj[300005];
ll ans;

ll getGain(int node, int parent) {
    vector<ll> scores;
    scores.push_back(0);
    scores.push_back(0);
    for (pair<int, ll> edge : adj[node]) {
        int to = edge.first;
        if (to == parent)
            continue;
        ll dis = edge.second;
        scores.push_back(getGain(to, node) - dis);
        sort(all(scores));
        reverse(all(scores));
        while (sz(scores) > 2)
            scores.pop_back();
    }
    sort(all(scores));
    ans = max(ans, scores[0]+scores[1]+w[node]);
    return scores[1]+w[node];
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    rep(i,0,n) {
        cin >> w[i];
    }
    rep(i,0,n-1)  {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        --u;--v;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    getGain(0, -1);
    cout << ans << endl;
}
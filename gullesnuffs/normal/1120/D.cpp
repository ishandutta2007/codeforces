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

ll c[200005];
vector<int> adj[200005];
map<pair<pair<int, bool>, bool>, ll> cache;
set<int> optimalNodes;

ll getCost(int node, int parent, bool full, bool getNodes) {
    auto key = make_pair(make_pair(node, full), getNodes);
    if (cache.count(key)) {
        return cache[key];
    }
    ll allFullCost = 0;
    vector<ll> partialSavings;
    for (auto to : adj[node]) {
        if (to == parent)
            continue;
        ll fullCost = getCost(to, node, true, false);
        ll partialCost = getCost(to, node, false, false);
        allFullCost += fullCost;
        partialSavings.push_back(fullCost - partialCost);
    }
    sort(all(partialSavings));
    reverse(all(partialSavings));
    ll ans[2];
    ll worstPartialSavings[2] = {ll(1e18), ll(1e18)};
    ll bestPartialSavings[2] = {ll(1e18), ll(1e18)};
    rep(useParent,0,2) {
        ll res = allFullCost;
        if (useParent)
            res += c[node];
        rep(i,0,min(1, min(sz(partialSavings), useParent+(1-full)))) {
            res -= partialSavings[i];
            worstPartialSavings[useParent] = partialSavings[i];
            if (i+1 == sz(partialSavings)) {
                bestPartialSavings[useParent] = 0;
            }
            else {
                bestPartialSavings[useParent] = partialSavings[i+1];
            }
        }
        if (!useParent && full && node && sz(adj[node]) == 1)
            res = 1e18;
        ans[useParent] = res;
    }
    if (getNodes) {
        if (ans[1] <= ans[0]) {
            optimalNodes.insert(node);            
        }
        ll worstAcceptablePartialSavings = -1;
        ll bestAcceptablePartialSavings = -1;
        rep(useParent,0,2) {
            if (ans[useParent] <= ans[!useParent]) {
                worstAcceptablePartialSavings = max(worstAcceptablePartialSavings, worstPartialSavings[useParent]);
                bestAcceptablePartialSavings = max(bestAcceptablePartialSavings, bestPartialSavings[useParent]);
            }
        }
        if (sz(partialSavings)) {
            //cerr << "Node=" << node << " worst=" << worstAcceptablePartialSavings << " best=" << bestAcceptablePartialSavings << endl;
        }
        for (auto to : adj[node]) {
            if (to == parent)
                continue;
            ll fullCost = getCost(to, node, true, false);
            ll partialCost = getCost(to, node, false, false);
            allFullCost += fullCost;
            ll ps = fullCost - partialCost;
            if (ps >= worstAcceptablePartialSavings) {
                getCost(to, node, false, true);
            }
            if (ps <= bestAcceptablePartialSavings) {
                getCost(to, node, true, true);
            }
        }
    }
    ll bestAns = min(ans[0], ans[1]);
    cache[key] = bestAns;
    //cerr << "Node=" << node << " full=" << full << " cost=" << bestAns << endl;
    return bestAns;
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    rep(i,0,n)
        cin >> c[i];
    rep(i,0,n-1) {
        int a, b;
        cin >> a >> b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = getCost(0, -1, true, true);
    cout << ans << " " << sz(optimalNodes) << endl;
    for (auto x : optimalNodes)
        cout << (x+1) << " ";
    cout << endl;
}
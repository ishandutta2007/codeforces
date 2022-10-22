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

int parent[200005][20];

int getParent(int ind, int steps) {
    rep(i,0,20) {
        if (steps&(1<<i)) {
            ind = parent[ind][i];
            if (ind == -1)
                return -1;
        }
    }
    return ind;
}

int main(){
	ios::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n);
    vi pinv(n);
    rep(i,0,n) {
        cin >> p[i];
        --p[i];
        pinv[p[i]] = i;
    }
    vector<int> a(m);
    rep(i,0,m) {
        cin >> a[i];
        --a[i];
    }
    vector<int> lastSeen(n, -1);    
    vector<pair<int, int>> ans;
    rep(i,0,m) {
        parent[i][0] = lastSeen[p[(pinv[a[i]]-1+n)%n]];
        rep(j,1,20) {
            if (parent[i][j-1] == -1)
                parent[i][j] = -1;
            else 
                parent[i][j] = parent[parent[i][j-1]][j-1];
        }
        int x = getParent(i, n-1);
        ans.emplace_back(x, -i);
        lastSeen[a[i]] = i;
    }
    sort(all(ans));
    vector<pair<int, int>> newAns;
    for (auto it : ans) {
        if (it.first == -1)
            continue;
        while (sz(newAns) && newAns.back().second >= -it.second) {
            newAns.pop_back();
        }
        newAns.push_back(make_pair(it.first, -it.second));
    }
    ans = newAns;
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        auto it = lower_bound(all(ans), make_pair(l, -2));
        if (it != ans.end() && it->second <= r)
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}
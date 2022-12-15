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
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v); g[v].insert(u);
    }
    int u;
    cin >> u;
	if(u != 1) {
		cout << "No\n";
		return 0;
	}
    vis[u] = true;
    q.push(u);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vector<int> rem;
        for(int v : g[u]) {
            if(vis[v]) rem.push_back(v);
        }
        for(int v : rem) {
            g[u].erase(v);
        }
        while(!g[u].empty()) {
            int v;
            cin >> v;
            if(!g[u].count(v)) {
                cout << "No\n";
                return 0;
            } else {
                vis[v] = true;
                q.push(v);
                g[u].erase(v);
            }
        }
    }
    cout << "Yes\n";
}
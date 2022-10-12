#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int n, far = 0;
vector<int> adj[500001];
pair<int, int> res[500001];

void dfs(int p, int i, int a, int b) {
    res[i] = {a, b};
    for (int j : adj[i])
        if (j != p) {
            b--;
            far += adj[j].size();
            dfs(i, j, b, far);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    fin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b; fin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    far = adj[0].size()+2;
    dfs(0, 0, 1, far);
    for (int i = 0; i < n; i++)
        cout << res[i].first << " " << res[i].second << "\n";
}
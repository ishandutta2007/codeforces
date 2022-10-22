#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<vector<int>>& conn, vector<int> indeg)
{
    int N = conn.size();
    queue<int> Q;
    for(int i=0; i<N; ++i) if(indeg[i] == 0) Q.emplace(i);
    while(!Q.empty())
    {
        int x = Q.front(); Q.pop();
        for(int a: conn[x]) if(--indeg[a] == 0) Q.emplace(a);
    }
    for(int x: indeg) if(x) return false;
    return true;
}

void dfs(const vector<vector<int>>& conn, vector<bool>& vis, int a)
{
    if(vis[a]) return;
    vis[a] = true;
    for(auto x: conn[a]) dfs(conn, vis, x);
}

string solve(const vector<vector<int>>& conn, const vector<vector<int>>& revconn)
{
    int N = conn.size(); vector<bool> vis(N), rvis(N);
    string ans(N, 'E');
    for(int i=0; i<N; ++i)
    {
        if(!vis[i] && !rvis[i]) ans[i] = 'A';
        dfs(conn, vis, i);
        dfs(revconn, rvis, i);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> conn(N), revconn(N); vector<int> indeg(N);
    for(int i=0; i<M; ++i)
    {
        int a, b; cin >> a >> b; --a; --b;
        conn[a].push_back(b); revconn[b].push_back(a);
        ++indeg[b];
    }
    if(!possible(conn, indeg))
    {
        cout << -1 << endl;
        return 0;
    }
    string ans = solve(conn, revconn);
    cout << count(ans.begin(), ans.end(), 'A') << endl;
    cout << ans << endl;
}
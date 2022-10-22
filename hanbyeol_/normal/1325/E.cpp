#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    const int sqrtMAXN = 1000; const int MAXN = sqrtMAXN*sqrtMAXN;
    vector<bool> isPrime(MAXN+1, true); isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=MAXN; ++i) if(isPrime[i])
    {
        for(int j=2*i; j<=MAXN; j += i) isPrime[j] = false;
    }
    isPrime[1] = true; // temporarily consider 1 also as prime

    vector<int> Pindex(MAXN+1);
    int cn = 0;
    for(int i=1; i<=MAXN; ++i) if(isPrime[i]) Pindex[i] = cn++;

    int sN = 0;
    for(int i=1; i<=sqrtMAXN; ++i) if(isPrime[i]) ++sN;

    // vector<vector<int>> conn(sN); vector<vector<int>> D2(sN, vector<int>(sN)); vector<vector<int>> adj(cn);
    vector<vector<int>> conn(cn);
    vector<bool> dup(MAXN+1);

    int N; cin >> N; bool a2 = false;
    for(int i=0; i<N; ++i)
    {
        int v; cin >> v;
        vector<int> P;
        for(int j=2; j*j<=v; ++j)
        {
            bool ok = false;
            while(v%j == 0)
            {
                ok = !ok;
                v /= j;
            }
            if(ok) P.push_back(j);
        }
        if(v != 1) P.push_back(v);
        assert(P.size() <= 2);
        if(P.empty())
        {
            cout << 1 << endl;
            return 0;
        }
        if(P.size() == 1) P.push_back(1);
        int r = P[0]*P[1]; if(dup[r]) a2 = true;
        dup[r] = true;

        int a = Pindex[P[0]], b = Pindex[P[1]]; if(a > b) swap(a, b);
        conn[a].push_back(b); conn[b].push_back(a);
        //if(b < sN) conn[a].push_back(b), conn[b].push_back(a);
        //else adj[b].push_back(a);
    }
    if(a2)
    {
        cout << 2 << endl;
        return 0;
    }
    /* for(vector<int>& x: adj)
        for(int i=0; i<(int)x.size(); ++i)
            for(int j=0; j<i; ++j)
                ++D2[x[i]][x[j]], ++D2[x[j]][x[i]];

    int ans = N+1;
    for(int i=0; i<sN; ++i) for(int j=0; j<i; ++j)
    {
        if(D2[i][j])
        {
            int nV = conn.size(); conn.push_back({});
            // i - nV && nV - j
            conn[i].push_back(nV); conn[nV].push_back(i);
            conn[j].push_back(nV); conn[nV].push_back(j);
        }
        if(D2[i][j] >= 2) ans = 4; //  a - p - b - q - a 
    } */

    int ans = N+1;

    // calculate girth of conn
    for(int r=0; r<sN; ++r)
    {
        vector<int> dis(conn.size()); vector<bool> vis(conn.size());
        queue<int> Q; Q.emplace(r); vis[r] = true; dis[r] = 0;
        while(!Q.empty())
        {
            int v = Q.front(); Q.pop();
            for(auto x: conn[v])
            {
                if(vis[x])
                {
                    if(dis[x] == dis[v] || dis[x] == dis[v] + 1)
                        ans = min(ans, dis[x] + dis[v] + 1);
                }
                else
                {
                    vis[x] = true;
                    dis[x] = dis[v]+1;
                    Q.push(x);
                }
            }
        }
    }

    if(ans == N+1) ans = -1;
    cout << ans << endl;
    return 0;
}
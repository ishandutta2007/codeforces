#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi2")
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> test(int x, const vector<vector<string>> &D)
{
    vector<pair<int, int>> V;
    vector<bool> vis(D.size());
    vis[0] = vis[x] = 1;
    V.emplace_back(0, x);
    function<void(int, int)> dfs = [&](int a, int p)
    {
        // d(z, a) = d(p, a) then do
        for (int z = 0; z < (int)D.size(); z++)
            if (!vis[z] && D[z][p][a] == '1')
            {
                V.emplace_back(z, a);
                vis[z] = 1;
                dfs(z, a);
            }
    };
    dfs(0, x);
    dfs(x, 0);
    return V;
}
bool check(vector<pair<int, int>> V, const vector<vector<string>> &D)
{
    if (V.size() + 1 != D.size())
        return false;
    int N = D.size();
    vector<vector<int>> A(N, vector<int>(N, N));
    for (auto [a, b] : V)
        A[a][b] = A[b][a] = 1;
    for (int i = 0; i < N; i++)
        A[i][i] = 0;
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (A[i][j] == N)
                return false;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            for (int k = 0; k < N; k++)
                if ((A[i][k] == A[j][k]) != (D[i][j][k] == '1'))
                    return false;
    return true;
}

// D[X][Y][Z]: d(x, z) = d(y, z)
vector<pair<int, int>> solve(const vector<vector<string>> &D)
{
    int N = D.size();
    for (int i = 1; i < N; i++)
    {
        auto ret = test(i, D);
        if (check(ret, D))
            return ret;
    }
    return {};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<vector<string>> V(N, vector<string>(N));
        for (int i = 0; i < N; i++)
        {
            V[i][i] = string(N, '1');
            for (int j = i + 1; j < N; j++)
            {
                cin >> V[i][j];
                V[j][i] = V[i][j];
            }
        }
        auto ans = solve(V);
        if (ans.empty())
            cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
            for (auto [a, b] : ans)
                cout << 1 + a << " " << 1 + b << endl;
        }
    }
}
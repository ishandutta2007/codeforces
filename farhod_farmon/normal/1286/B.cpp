#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;

using namespace std;

int n;
int c[N];
int res[N];
vector < int > v[N], A[N];

void dfs(int x)
{
        for(int y: v[x]){
                dfs(y);
                for(int z: A[y]){
                        A[x].push_back(z);
                }
        }
        if(c[x] > A[x].size()){
                cout << "NO" << "\n";
                exit(0);
        }
        A[x].push_back(0);
        int need = c[x];
        for(int i = A[x].size() - 1; i > need; i--){
                swap(A[x][i], A[x][i - 1]);
        }
        A[x][need] = x;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x >> c[i];
                v[x].push_back(i);
        }
        int root = v[0][0];
        dfs(root);
        for(int i = 0; i < n; i++){
                res[A[root][i]] = i + 1;
        }

        cout << "YES" << "\n";
        for(int i = 1; i <= n; i++){
                cout << res[i] << " \n"[i == n];
        }
}
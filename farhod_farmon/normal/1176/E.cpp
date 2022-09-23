#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
int a[N];
vector < int > v[N];

void dfs(int x, int c)
{
        if(a[x]){
                return;
        }
        a[x] = c;
        for(int y: v[x]){
                dfs(y, 3 - c);
        }
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                a[i] = 0;
        }
        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        dfs(1, 1);
        vector < int > A, B;
        for(int i = 1; i <= n; i++){
                if(a[i] == 1){
                        A.push_back(i);
                } else{
                        B.push_back(i);
                }
        }
        if(B.size() < A.size()){
                A = B;
        }
        cout << A.size() << "\n";
        for(int x: A){
                cout << x << " ";
        }
        cout << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}
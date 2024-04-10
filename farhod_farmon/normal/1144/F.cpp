#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int A[N];
int B[N];
int col[N];
vector < int > v[N];

void dfs(int x, int c)
{
        if(col[x]){
                if(col[x] != c){
                        cout << "NO" << "\n";
                        exit(0);
                }
                return;
        }
        col[x] = c;
        for(int y: v[x]){
                dfs(y, 3 - c);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;

        for(int i = 1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);

                A[i] = x; B[i] = y;
        }

        for(int i = 1; i <= n; i++){
                if(!col[i]){
                        dfs(i, 1);
                }
        }

        cout << "YES" << "\n";
        for(int i = 1; i <= m; i++){
               int x = A[i], y = B[i];
               cout << (col[x] < col[y]);
        }
}
#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 303;

using namespace std;

int n, m;
char a[N][N];

void solve()
{
        cin >> n;
        vector < pair < int, int > > A[3];
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        cin >> a[i][j];
                        if(a[i][j] == 'X'){
                                A[(i + j) % 3].push_back({i, j});
                        }
                }
        }
        if(A[1].size() < A[0].size()){
                A[0] = A[1];
        }
        if(A[2].size() < A[0].size()){
                A[0] = A[2];
        }
        for(auto p: A[0]){
                a[p.fi][p.se] = 'O';
        }
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        cout << a[i][j];
                }
                cout << "\n";
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll inf = (1LL<<52);

ll a[505][505], b[505][505];
ll d[505][505], ans[505];
int n, x[505];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>b[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        cin>>x[i];
    }
    for(int i = 1; i <= n/2; i++){
        swap(x[i], x[n+1-i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] = b[x[i]][x[j]];
            d[i][j] = inf;
        }
    }
    d[1][1] = 0;
    for(int k = 2; k <= n; k++){
        for(int i = 1; i <= k; i++){
            d[i][k] = a[i][k];
            d[k][i] = a[k][i];
        }
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++){
                d[i][k] = min(d[i][k], d[i][j] + d[j][k]);
                d[k][i] = min(d[k][i], d[k][j] + d[j][i]);
            }
        }
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
        ans[k] = 0;
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++){
                ans[k] += d[i][j];
                // cout<<d[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<endl;
    }
    ans[1] = 0;
    for(int k = n; k >= 1; k--){
        cout<<ans[k]<<" ";
    }
    cout<<endl;
}
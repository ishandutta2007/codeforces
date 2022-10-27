#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;

pair<int, int> arr[105], g[305][305], dp[105][3];
int n;

int get(int x, int y, int p){
    return 3*n*x + 3*y + p;
}

pair<int, int> add(pair<int, int> &a, pair<int, int> &b){
    return {a.first + b.first, a.second + b.second};
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    cin>>n;
    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>x;
            arr[x-1] = {i, j};
        }
    }
    int m = n*n;
    for(int i = 0; i < 305; i++){
        for(int j = 0; j < 305; j++){
            g[i][j] = {inf, inf};
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i == j)continue;
            int dx = abs(arr[i].first - arr[j].first);
            int dy = abs(arr[i].second - arr[j].second);
            if(dx == 0 || dy == 0){
                g[get(arr[i].first, arr[i].second, 0)][get(arr[j].first, arr[j].second, 0)] = {1, 0};
                g[get(arr[j].first, arr[j].second, 0)][get(arr[i].first, arr[i].second, 0)] = {1, 0};
            }
            if(dx == dy){
                g[get(arr[i].first, arr[i].second, 1)][get(arr[j].first, arr[j].second, 1)] = {1, 0};
                g[get(arr[j].first, arr[j].second, 1)][get(arr[i].first, arr[i].second, 1)] = {1, 0};
            }
            if(dx > 0 && dy > 0 && dx + dy == 3){
                g[get(arr[i].first, arr[i].second, 2)][get(arr[j].first, arr[j].second, 2)] = {1, 0};
                g[get(arr[j].first, arr[j].second, 2)][get(arr[i].first, arr[i].second, 2)] = {1, 0};
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                g[get(arr[i].first, arr[i].second, j)][get(arr[i].first, arr[i].second, k)] = {(j != k), (j != k)};
            }
        }
    }
    int M = 3*m;
    for(int k = 0; k < M; k++){
        for(int i = 0; i < M; i++){
            for(int j = 0; j < M; j++){
                g[i][j] = min(g[i][j], add(g[i][k], g[k][j]));
            }
        }
    }
    dp[0][0] = dp[0][1] = dp[0][2] = {0,0};
    for(int i = 1; i < m; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = {inf, inf};
            for(int k = 0; k < 3; k++){
                pair<int,int> tmp = add(dp[i-1][k], g[get(arr[i-1].first,arr[i-1].second,k)][get(arr[i].first,arr[i].second,j)]);
                dp[i][j] = min(dp[i][j], tmp);
            }
        }
    }
    pair<int, int> ans = dp[m-1][0];
    ans = min(ans, dp[m-1][1]);
    ans = min(ans, dp[m-1][2]);
    cout<<ans.first<<" "<<ans.second<<endl;
}
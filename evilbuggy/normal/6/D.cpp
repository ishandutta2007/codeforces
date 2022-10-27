#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 10000000;

int n, a, b, maxi, h[12];
map<pair<int,int>, int> dp[12], par[12];

int dfs(int i, int curv, int prev){
    if(i == n){
        if(curv < 0)return 0;
        return inf;
    }
    if(dp[i].find({curv, prev}) != dp[i].end())return dp[i][{curv, prev}];
    int nexv = h[i+1];
    int nmov = inf, ret = inf;
    for(int x = 0; x <= maxi; x++){
        if(prev - b*x >= 0)continue;
        int tmp = dfs(i + 1, nexv - b*x, curv - a*x);
        if(tmp + x < ret){
            ret = tmp + x;
            nmov = x;
        }
    }
    dp[i][{curv, prev}] = ret;
    par[i][{curv, prev}] = nmov;
    return ret;
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

    cin>>n>>a>>b;
    maxi = 15/b + 2;
    for(int i = 1; i <= n; i++){
        cin>>h[i];
    }
    int nmov = dfs(2, h[2], h[1]);
    cout<<nmov<<endl;
    assert(nmov < inf);
    int curv = h[2], prev = h[1];
    for(int i = 2; i < n; i++){
        int tmov = par[i][{curv, prev}];
        for(int j = 0; j < tmov; j++){
            cout<<i<<" ";
        }
        prev = curv - a*tmov;
        curv = h[i+1] - b*tmov;
    }
}
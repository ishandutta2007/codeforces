#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool g[45][45];
int dp1[(1<<20)];
int dp2[(1<<20)];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    memset(g, false, sizeof(g));
    int n, m, type;
    cin>>n>>m;
    set<int> arr;
    map<string, int> hsh;
    string s;
    int ptr = 0;
    for(int i = 0; i < n; i++){
        cin>>type;
        if(type == 1){
            if(!arr.empty()){
                for(auto x : arr){
                    for(auto y : arr){
                        if(x != y){
                            g[x][y] = true;
                        }
                    }
                }
            }
            arr.clear();
        }else{
            cin>>s;
            if(hsh.find(s) == hsh.end()){
                hsh[s] = ptr++;
            }
            arr.insert(hsh[s]);
        }
    }
    if(!arr.empty()){
        for(auto x : arr){
            for(auto y : arr){
                if(x != y){
                    g[x][y] = true;
                }
            }
        }
    }
    arr.clear();
    int n1 = m/2;
    int n2 = m - n1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(i != j)g[i][j] ^= true;
        }
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for(int i = 0; i < n1; i++){
        dp1[(1<<i)] = 1;
    }
    for(int i = 0; i < n2; i++){
        dp2[(1<<i)] = 1;
    }
    int ans = 0;
    for(int mask = 0; mask < (1<<n1); mask++){
        ans = max(ans, dp1[mask]);
        if(!dp1[mask])continue;
        for(int i = 0; i < n1; i++){
            if(!((mask>>i)&1)){
                bool tmp = true;
                for(int j = 0; j < n1; j++){
                    if((mask>>j)&1)tmp &= g[i][j];
                }
                if(tmp)dp1[mask^(1<<i)] = dp1[mask] + 1;
            }
        }
    }
    for(int mask = 0; mask < (1<<n2); mask++){
        ans = max(ans, dp2[mask]);
        for(int i = 0; i < n2; i++){
            if(!((mask>>i)&1)){
                bool tmp = true;
                for(int j = 0; j < n2; j++){
                    if((mask>>j)&1)tmp &= g[i + n1][j + n1];
                }
                if(tmp)dp2[mask^(1<<i)] = dp2[mask] + 1;
            }
        }
    }
    for(int i = 0; i < n2; i++){
        for(int mask = 0; mask < (1<<n2); mask++){
            if((mask>>i)&1){
                dp2[mask] = max(dp2[mask], dp2[mask^(1<<i)]);
            }
        }
    }
    for(int mask = 0; mask < (1<<n1); mask++){
        int nmask = (1<<n2) - 1;
        for(int i = 0; i < n1; i++){
            if(mask&(1<<i)){
                for(int j = 0; j < n2; j++){
                    if(!g[i][n1 + j])nmask &= ((1<<n2) - (1<<j) - 1);
                }
            }
        }
        ans = max(ans, dp1[mask] + dp2[nmask]);
    }
    cout<<ans<<endl;
}
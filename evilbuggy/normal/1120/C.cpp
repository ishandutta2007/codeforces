#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int kmp(string &s, string &t){
    int n = s.size(), m = t.size();
    vector<int> f(m);
    f[0] = 0;
    int i = 1, j = 0;
    while(i < m){
        if(t[i] == t[j]){
            f[i] = j + 1;
            i++; j++;
        }else if(j == 0){
            f[i] = 0;
            i++;
        }else{
            j = f[j-1];
        }
    }
    i = j = 0;
    int ans = 0;
    while(i < n){
        if(j == m){
            return m;
        }
        if(s[i] == t[j]){
            i++; j++;
            ans = max(ans, j);
        }else if(j == 0){
            i++;
        }else{
            j = f[j-1];
        }
    }
    return ans;
}

bool pos[5005][5005];
int dp[5005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, a, b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    memset(pos, false, sizeof(pos));
    for(int i = 0; i < n; i++){
        string s1 = s.substr(0, i);
        string s2 = s.substr(i);
        int len = kmp(s1, s2);
        for(int j = 0; j < len; j++){
            pos[i][i + j] = true;
        }
    }
    dp[0] = a;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1] + a;
        for(int j = 0; j <= i; j++){
            if(pos[j][i]){
                int cost = b + ((j != 0)?dp[j-1]:0);
                dp[i] = min(dp[i], cost);
            }
        }
    }
    cout<<dp[n-1]<<endl;
}
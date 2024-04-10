#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e8;

pair<int,int> dp[100005], mdp[100005];
int cost[100005], noa[100005], nob[100005], noq[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    string s;
    cin>>n>>s>>m;
    if(n < m){
        cout<<0<<endl;
        exit(0);
    }
    if(m == 1){
        int cnt = 0;
        for(auto ch : s){
            cnt += (ch == '?');
        }
        cout<<cnt<<endl;
        exit(0);
    }
    noa[0] = (s[0] == 'a');
    nob[0] = (s[0] == 'b');
    noa[1] = (s[1] == 'a');
    nob[1] = (s[1] == 'b');
    noq[0] = (s[0] == '?');
    noq[1] = (s[1] == '?') + noq[0];
    for(int i = 2; i < n; i++){
        noa[i] = noa[i-2] + (s[i] == 'a');
        nob[i] = nob[i-2] + (s[i] == 'b');
        noq[i] = noq[i-1] + (s[i] == '?');
    }
    for(int i = m - 1; i < n; i++){
        if(m&1){
            int cntb = nob[i];
            if(i-m-1 >= 0)cntb -= nob[i-m-1];
            int cnta = noa[i-1];
            if(i-m >= 0)cnta -= noa[i-m];
            if(cnta || cntb)cost[i] = inf;
            else cost[i] = noq[i] - ((i >= m)?noq[i-m]:0);
        }else{
            int cnta = noa[i];
            if(i-m >= 0)cnta -= noa[i-m];
            int cntb = nob[i-1];
            if(i-m-1 >= 0)cntb -= nob[i-m-1];
            if(cnta || cntb)cost[i] = inf;
            else cost[i] = noq[i] - ((i >= m)?noq[i-m]:0);
        }
    }
    for(int i = 0; i < m-1; i++){
        cost[i] = inf;
    }
    // for(int i = 0; i < n; i++){
    //     cout<<cost[i]<<endl;
    // }
    for(int i = 0; i < n; i++){
        if(cost[i] == inf){
            dp[i] = {0, 0};
        }else{
            dp[i] = {1, cost[i]};
            if(i-m >= 0){
                dp[i].first += mdp[i-m].first;
                dp[i].second += mdp[i-m].second;
            }
        }
        if(i != 0)mdp[i] = mdp[i-1];
        else mdp[i] = dp[i];
        if(mdp[i].first < dp[i].first)mdp[i] = dp[i];
        else if(mdp[i].first == dp[i].first && mdp[i].second > dp[i].second)mdp[i] = dp[i];
    }
    pair<int,int> ans = {0, 0};
    for(int i = 0; i < n; i++){
        if(dp[i].first > ans.first)ans = dp[i];
        else if(ans.first == dp[i].first && ans.second > dp[i].second)ans = dp[i];
    }
    cout<<ans.second<<endl;
}
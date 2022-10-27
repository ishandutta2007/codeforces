#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<int> g[100005];
int p[100005];
ll s[100005], a[100005];

bool dfs(int v, int d){
    if(d%2 == 0){
        if(g[v].size() == 0){
            a[v] = 0;
            return true;
        }
        ll mini = s[g[v][0]];
        for(int i = 0; i < g[v].size(); i++){
            mini = min(s[g[v][i]], mini);
        }
        if(mini < s[p[v]]){
            return false;
        }
        a[v] = mini - s[p[v]];
        s[v] = mini;
    }else{
        if(s[v] < s[p[v]])return false;
        a[v] = s[v] - s[p[v]];
    }
    bool tmp = true;
    for(int i = 0; i < g[v].size(); i++){
        tmp &= dfs(g[v][i], d+1);
    }
    return tmp;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i = 2; i <= n; i++){
        cin>>p[i];
        g[p[i]].push_back(i);
    }
    p[1] = 0;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
    }
    a[0] = 0;
    s[0] = 0;
    if(dfs(1, 1)){
        ll sum = 0;
        bool tmp = false;
        for(int i = 1; i <= n; i++){
            sum += a[i];
            tmp |= (a[i] < 0);
        }
        if(!tmp)cout<<sum<<endl;
        else cout<<-1<<endl;
    }else{
        cout<<-1<<endl;
    }

}
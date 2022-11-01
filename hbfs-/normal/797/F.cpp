#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll INF = 0x3f3f3f3f3f3f3f;

const int Max = 5005;
ll pm[Max];
pair<ll,int> h[Max];

ll sum[Max];

ll dp[2][Max];

struct OrderedQueue{
    ll val[Max];
    int id[Max];
    int l,r;

    void init(){
        l = 0;
        r = 0;
    }

    void push(ll v,int i){
        while(l<r && v<val[r-1]){
            r--;
        }
        val[r] = v;
        id[r] = i;
        r++;
    }

    ll front(){
        return val[l];
    }

    void remove(int i){
        while(l<r && id[l]<=i){
            l++;
        }
    }

}que;

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>pm[i];
    }

    int tot = 0;
    for(int i=1;i<=m;i++){
        cin>>h[i].first>>h[i].second;
        tot += h[i].second;
    }
    if(tot < n){
        cout<<-1<<endl;
        return 0;
    }

    sort(pm+1,pm+n+1);
    sort(h+1,h+m+1);

    for(int i=0;i<Max;i++){
        dp[0][i] = dp[1][i] = INF;
    }

    int cur = 0;
    int pre = 1;
    dp[cur][0] = 0;
    dp[pre][0] = 0;
    for(int i=1;i<=m;i++){
        swap(cur,pre);
        for(int j=1;j<=n;j++){
            sum[j] = sum[j-1] + abs(h[i].first - pm[j]);
        }
        que.init();
        for(int j=0;j<=n;j++){
            que.push( dp[pre][j] - sum[j], j);
            dp[cur][j] = que.front() + sum[j];
            que.remove( j - h[i].second);
        }
    }

    cout<<dp[cur][n]<<endl;
    return 0;
}
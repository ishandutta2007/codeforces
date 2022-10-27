#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int dist[505][5005];
int vis[505][5005];
pair<int, int> par[505][5005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, s;
    cin>>d>>s;

    for(int i = 0; i <= d; i++){
        for(int j = 0; j <= s; j++){
            dist[i][j] = inf;
            vis[i][j] = 0;
            par[i][j] = make_pair(i,j);
        }
    }

    dist[0][0] = 0;
    queue<pair<int,int> >qq;
    qq.push(make_pair(0,0));
    while(!qq.empty()){
        pair<int,int> y = qq.front();
        qq.pop();
        int rem = y.first, sum = y.second;
        if(vis[rem][sum] == 1)continue;
        // cout<<rem<<" "<<sum<<endl;
        if(sum > s)continue;
        vis[rem][sum] = 1;
        for(int dig = 0; dig < 10; dig++){
            int nsum = sum+dig, nrem = (10*rem+dig)%d;
            if(vis[nrem][nsum] == 1)continue;
            if(dist[nrem][nsum] > dist[rem][sum] + 1){
                dist[nrem][nsum] = dist[rem][sum] + 1;
                par[nrem][nsum] = make_pair(rem, sum);
                qq.push(make_pair(nrem, nsum));
            }
        }
    }
    // cout<<dist[0][s]<<endl;
    if(dist[0][s] == inf){
        cout<<-1<<endl;
        return 0;
    }
    int x = 0, y = s;
    vector<int>ans;
    while(x != 0 || y != 0){
        int nx = par[x][y].first, ny = par[x][y].second;
        ans.push_back(y-ny);
        x = nx;
        y = ny;
    }
    int n = ans.size();
    for(int i = n-1; i >= 0; i--){
        cout<<ans[i];
    }
    cout<<endl;
}
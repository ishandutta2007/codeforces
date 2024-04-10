#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
struct Query{
    int x1,y1,x2,y2;
    Query(int x1, int y1, int x2,int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    Query() {}
};
vector<pair<int,int>> delta = {{-1,0}, {1,0}, {0,-1}, {0,1}};
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> grid(n, vector<int>(m));
    cin>>grid;
    for(auto &v : grid) for(auto &x : v) --x;
    int q;
    cin>>q;
    vector<Query> queries(q);
    for(auto &[x1,y1,x2,y2] : queries){
        cin>>x1>>y1>>x2>>y2;
        --x1;--y1;--x2;--y2;
    }
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        ans[i] = abs(queries[i].x1 - queries[i].x2) + abs(queries[i].y1 - queries[i].y2);
    }
    vector<vector<pair<int,int>>> colors(k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            colors[grid[i][j]].push_back(pair(i,j));
        }
    }
    for(int c=0;c<k;c++){
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<bool> colorvis(k);
        queue<pair<int,int>> bfs;
        for(const auto &[x,y] : colors[c]){
            bfs.push(pair(x,y));
            dp[x][y] = 0;
        }
        colorvis[c] = 1;
        while(!bfs.empty()){
            auto [x,y] = bfs.front();
            bfs.pop();
            for(const auto &[dx,dy] : delta){
                if(x + dx < 0 || x + dx >= n) continue;
                if(y + dy < 0 || y + dy >= m) continue;
                if(~dp[x+dx][y+dy]) continue;
                dp[x+dx][y+dy] = dp[x][y] + 1;
                bfs.push(pair(x+dx,y+dy));
            }
            if(!colorvis[grid[x][y]]){
                colorvis[grid[x][y]] = 1;
                for(const auto &[x2,y2] : colors[grid[x][y]]){
                    if(~dp[x2][y2]) continue;
                    dp[x2][y2] = dp[x][y] + 1;
                    bfs.push(pair(x2,y2));
                }
            }
        }
        for(int i=0;i<q;i++){
            const auto &[x1,y1,x2,y2] = queries[i];
            ans[i] = min(ans[i], dp[x1][y1] + dp[x2][y2] + 1);
        }
    }
    for(const auto &x : ans){
        cout<<x<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
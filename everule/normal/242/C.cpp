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
const int p = 1e9 + 7;
const int MAXC = 1e5;
set<pair<int,int>> allowed;
map<pair<int,int>, int> dist; 
vector<pair<int,int>> delta = {{1,0},{-1,0},{0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
void solve(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int r,a,b;
        cin>>r>>a>>b;
        for(int j=a;j<=b;j++){
            allowed.insert({r,j});
        }
    }
    queue<pair<int,int>> bfs;
    bfs.push({x1,y1});
    while(!bfs.empty()){
        const auto &[x,y] = bfs.front();
        for(const auto &[dx,dy] : delta){
            if(!allowed.count({x+dx,y+dy})) continue;
            if(dist.count({x+dx,y+dy})) continue;
            dist[{x+dx,y+dy}] = dist[{x,y}] + 1;
            bfs.push({x+dx, y+dy});
        }
        bfs.pop();
    }
    if(dist.count({x2,y2})){
        cout<<dist[{x2,y2}];
    }
    else{
        cout<<"-1\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
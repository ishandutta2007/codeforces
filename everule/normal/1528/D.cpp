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
const int INF = 1e9 + 1000;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> cn(n, vector<int>(n, INF));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        cn[a][b] = c;
    }
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for(int i=0;i<n;i++) dist[i][i] = 0;
    for(int s=0;s<n;s++){
        vector<int> q(n, INF);
        q[s] = 0;
        vector<bool> processed(n);
        while(true){
            auto it = min_element(q.begin(), q.end());
            if(*it == INF) break;
            int a = (it - q.begin());
            assert(a >= 0);
            assert(a < n);
            for(int b=0;b<n;b++){
                int dest = (b + dist[s][a]) % n;
                if(dest != s) dist[s][dest] = min(dist[s][dest], dist[s][a] + cn[a][b]);
                else dist[s][(dest + 1) % n] = min(dist[s][(dest + 1) % n], dist[s][a] + cn[a][b] + 1);
            }
            if(a == s) dist[s][(s + 1) % n] = min(dist[s][(s + 1) % n], cn[s][s] + 1);
            for(int x=0;x<2*n;x++){
                if(x % n != s) dist[s][(x + 1) % n] = min(dist[s][(x + 1) % n], dist[s][x % n] + 1);
                else dist[s][(x + 1) % n] = min(dist[s][(x + 1) % n], dist[s][(x + n - 1) % n] + 2);
            }
            processed[a] = true;
            for(int i=0;i<n;i++){
                if(processed[i]) q[i] = INF;
                else q[i] = dist[s][i];
            }
        }
    }
    cout * dist;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
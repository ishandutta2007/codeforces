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
const int n = 25;
void solve(){
    int l,r;
    cin>>l>>r;
    vector<vector<int>> edges(n, vector<int>(n, -1));
    for(int i=1;i<n;i++) edges[0][i] = 1;
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n-1;j++){
            edges[i][j] = (1<<(i-1));
        }
    }
    int x = r - l;
    int y = 1;
    int d = 1;
    while(x){
        if(x & 1){
            edges[y][n-1] = d;
            d += (1<<(y-1));
        }
        ++y;
        x >>= 1;
    }
    int m = 0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(edges[i][j] != -1 && edges[i][j] <= r) ++m;
    cout<<"YES\n";
    cout<<n<<" "<<m<<"\n";
    for(int i=0;i<n;i++) if(edges[i][n-1] != -1) edges[i][n-1] += l-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j] != -1 && edges[i][j] <= r) cout<<i+1<<" "<<j+1<<" "<<edges[i][j]<<"\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
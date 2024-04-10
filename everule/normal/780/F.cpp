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
const int lgn = 64;
const int MAXN = 500;
bitset<MAXN> bls[2][lgn][MAXN];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,t;
        cin>>u>>v>>t;
        --u;--v;
        bls[t][0][u][v] = 1;
    }
    for(int b=1;b<lgn;b++){
        for(int i=0;i<n;i++){
            /*for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    bls[0][b][i] |= (bls[0][b-1][i][k] & bls[1][b-1][k][j]);
                    bls[1][b][i] |= (bls[1][b-1][i][k] & bls[0][b-1][k][j]);
                }
            }*/
            for(int k=0;k<n;k++){
                if(bls[0][b-1][i][k]){
                    bls[0][b][i] |= bls[1][b-1][k];
                }
                if(bls[1][b-1][i][k]){
                    bls[1][b][i] |= bls[0][b-1][k];
                }
            }
        }
    }
    ll ans = 0;
    int t = 0;
    vector<int> poss(n, 1);
    for(int b=lgn-1;b>=0;--b){
        vector<int> nposs(n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                nposs[j] |= (poss[i] & bls[t][b][i][j]);
            }
        }
        if(accumulate(nposs.begin(), nposs.end(), 0ll)){
            poss = nposs;
            t ^= 1;
            ans += (1ll<<b);
        }
    }
    if(ans > 1e18){
        cout<<"-1\n";
        return;
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
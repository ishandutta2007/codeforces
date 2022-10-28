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
void solve(){
    int n,m;
    cin>>n>>m;
    vector seq(n, vector<int>(m));
    cin>>seq;
    vector<int> order;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            order.push_back(i*m + j);
        }
    }
    sort(order.begin(), order.end(), [&](int x,int y){
        return seq[x/m][x%m] < seq[y/m][y%m];
    });
    for(int i=0;i<m;i++){
        seq[order[i]/m][order[i]%m] *= -1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(order[j]/m == i){
                cout<<seq[order[j]/m][order[j] % m] * -1<<" ";
                continue;
            }
            for(int k=0;k<m;k++){
                if(seq[i][k] > 0){
                    cout<<seq[i][k]<<" ";
                    seq[i][k] *= -1;
                    break;
                }
            }
        }
        cout<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
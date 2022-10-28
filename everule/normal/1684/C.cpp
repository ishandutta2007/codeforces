#include <bits/stdc++.h>
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
const int INF = 1e9 + 7;
void solve(){
    int n,m;
    cin>>n>>m;
    vector a(n, vector(m, 0));
    cin>>a;
    int mx_s = -1, mn_s = m;
    for(int i=0;i<n;i++){
        int lastmax = -INF;
        for(int j=0;j<m;j++){
            if(a[i][j] < lastmax){
                mx_s = max(mx_s, j);
            }
            lastmax = max(lastmax, a[i][j]);
        }
        int lastmin = INF;
        for(int j=m-1;j>=0;--j){
            if(a[i][j] > lastmin){
                mn_s = min(mn_s, j);
            }
            lastmin = min(lastmin, a[i][j]);
        }
    }
    if(mx_s == -1 && mn_s == m){
        cout<<"1 1"<<"\n";
        return;
    }
    assert(mx_s != -1 && mn_s != m);
    for(int i=0;i<n;i++){
        swap(a[i][mn_s], a[i][mx_s]);
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j-1] > a[i][j]){
                cout<<"-1\n";
                return;
            }
        }
    }
    cout<<mn_s+1<<" "<<mx_s+1<<"\n";
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
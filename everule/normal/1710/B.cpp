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
    vector<array<int, 2>> rains(n);
    vector<int> rel_points;
    rel_points.reserve(3 * n);
    for(auto &[x, p] : rains){
        cin>>x>>p;
        rel_points.push_back(x);
        rel_points.push_back(x + p);
        rel_points.push_back(x - p);
    }
    sort(rel_points.begin(), rel_points.end());
    rel_points.resize(unique(rel_points.begin(), rel_points.end()) - rel_points.begin());
    int rs = rel_points.size();
    vector<ll> rainfall_slope(rs);
    for(auto &[x, p] : rains){
        rainfall_slope[lower_bound(rel_points.begin(), rel_points.end(), x - p) - rel_points.begin()] += 1;
        rainfall_slope[lower_bound(rel_points.begin(), rel_points.end(), x) - rel_points.begin()] -= 2;
        rainfall_slope[lower_bound(rel_points.begin(), rel_points.end(), x + p) - rel_points.begin()] += 1;
    }
    vector<ll> rain_fall(rs);
    ll c_slope = rainfall_slope[0];
    for(int i=1;i<rs;i++){
        rain_fall[i] = rain_fall[i-1] + c_slope * (rel_points[i] - rel_points[i-1]);
        c_slope += rainfall_slope[i];
    }
    vector<ll> req_plus(rs), req_minus(rs);
    ll curr_req_minus = -INF;
    for(int i=0;i<rs;i++){
        if(rain_fall[i] > m){
            curr_req_minus = max(curr_req_minus, rain_fall[i] - m - rel_points[i]);
        }
        req_minus[i] = curr_req_minus;
    }
    ll curr_req_plus = -INF;
    for(int i=rs-1;i>=0;--i){
        if(rain_fall[i] > m){
            curr_req_plus = max(curr_req_plus, rain_fall[i] - m + rel_points[i]);
        }
        req_plus[i] = curr_req_plus;
    }
    for(auto &[x, p] : rains){
        int idx = lower_bound(rel_points.begin(), rel_points.end(), x) - rel_points.begin();
        if(p + x >= req_plus[idx] && p - x >= req_minus[idx]){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    cout<<"\n";
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
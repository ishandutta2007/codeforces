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
struct DSU{
    vector<int> parent;
    vector<int> sizof;
    int n;
    DSU(int N){
        n=N;
        parent.resize(n);
        sizof.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            sizof[i]=1;
        }
    }
    int get_size(int x){
        return sizof[find_set(x)];
    }
    int find_set(int v){
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sizof[a] < sizof[b]){
                swap(a, b);
            }
            parent[b] = a;
            sizof[a] += sizof[b];
        }
    }
};
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    cin>>a;
    sort(a.begin(), a.end());
    if(accumulate(a.begin(), a.end(), 0ll) + (n - 2) * a[0] > 0){
        cout<<"INF\n";
        return;
    }
    if(accumulate(a.begin(), a.end(), 0ll) + (n - 2) * a[n-1] < 0){
        cout<<"INF\n";
        return;
    }
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++) ps[i] = ps[i-1] + a[i-1];
    auto getT = [&](ll t){
        int nve = lower_bound(a.begin(), a.end(), -t) - a.begin();
        //cout<<t<<" "<<nve<<"\n";
        if(nve == 0){
            return (a[0] + t) * (ps[n] + n * t) - (a[0] + t) * (a[0] + t) - (n - 1) * t * t;
        }
        if(nve == n){
            return  (a[n-1] + t) * (ps[n] + n * t) - (a[n-1] + t) * (a[n-1] + t) - (n - 1) * t * t;
        }
        return (a[0] + t) * (ps[n] - ps[nve] + (n - nve) * t) + (a[n-1] + t) * (ps[nve] + nve * t) - (a[0] + t) * (a[n-1] + t) - (n - 1) * t * t;
    };
    ll mn = -1e6, mx = 1e6;
    ll ans = getT(0);
    while(mx - mn > 1){
        ll mid = (mn + mx) / 2;
        if(getT(mid) == getT(mid+1)){
            mn = mid;
            mx = mid + 1;
            break;
        }
        ans = max(ans, getT(mid));
        if(getT(mid) < getT(mid+1)){
            mn = mid + 1;
        }
        else{
            mx = mid - 1;
        }
    }
    ans = max(ans, max(getT(mn), getT(mx)));
    cout<<ans<<"\n";
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
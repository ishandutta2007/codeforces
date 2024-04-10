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
vector<int> spf;
void sieve(const int n){
    spf.assign(n, -1);
    for(int i=2;i<n;i++){
        if(spf[i] != -1) continue;
        spf[i] = i;
        for(int j=2*i;j<n;j+=i){
            if(spf[j] == -1) spf[j] = i; 
        }
    }
}
int MEX(vector<int> &x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
}
void solve(){
    int n;
    cin>>n;
    map<int, vector<array<int, 2>>> factors;
    vector<int> a(n);
    cin>>a;
    for(int i=0;i<n;i++){
        int x = a[i];
        while(x > 1) {
            int p = spf[x];
            int e = 0;
            while(spf[x] == p){
                x /= p;
                e++;
            }
            factors[p].push_back({e, i});
        }
    }
    vector<int> idx;
    ll g = 0;
    vector<int> rel_primes;
    for(auto &[p, v] : factors){
        sort(v.begin(), v.end());
        if(v.size() < n - 1) continue;
        rel_primes.push_back(p);
        if(v.size() == n - 1){
            vector<int> nv;
            for(auto &[e, id] : v) nv.push_back(id);
            idx.push_back(MEX(nv));
           v.insert(v.begin(), {0, MEX(nv)});
        }
        idx.push_back(v[0][1]);
        idx.push_back(v[1][1]);
        ll pe = 1;
        int e = v[0][0] + v[1][0];
        for(int i=0;i<e;i++) pe *= p;
        g *= p;
    }
    while(true){
        sort(idx.begin(), idx.end());
        idx.resize(unique(idx.begin(), idx.end()) - idx.begin());
        vector<int> red(idx.size());
        for(int i=0;i<idx.size();i++){
            red[i] = a[idx[i]];
            for(auto &p : rel_primes){
                while(red[i] % p == 0) red[i] /= p;
            }
        }
        bool has_failed = 0;
        int sz = idx.size();
        for(int i=0;i<sz;i++){
            int g = 0;
            for(int j=0;j<sz;j++){
                if(i == j) continue;
                g = gcd(g, red[j]);
            }
            if(g > 1){
                has_failed = 1;
                int p = spf[g];
                for(int i=0;i<n;i++){
                    if(a[i] % p != 0) idx.push_back(i);
                    if(idx.size() > sz + 1) break;
                }
                break;
            }
        }
        if(!has_failed) break;
    }
    int num_ele = idx.size();
    vector<int> wt(num_ele + 1);
    int num_op = 0;
    for(int i=1;i<=num_ele;i++){
        if(i % 2 == 1){
            wt[i] = 2 - i;
        }
        else{
            wt[i] = i - 2;
        }
    }
    vector<vector<int>> ops;
    for(int i=0;i<(1<<num_ele);i++){
        for(int j=0;j<abs(wt[__builtin_popcount(i)]);j++){
            ops.push_back({(wt[__builtin_popcount(i)] < 0 ? 1 : 0), __builtin_popcount(i)});
            for(int k=0;k<num_ele;k++){
                if(i & (1<<k)) ops.back().push_back(idx[k] + 1);
            }
        }
    }
    cout<<ops.size()<<"\n";
    cout * ops;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(2e6);
    solve();
}
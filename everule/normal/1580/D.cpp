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
const int INF = 1e9 + 7;
const ll INFLL = 1e18 + 7;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    /*function<vector<ll>(int, int)> brute = [&](int l,int r){
        int len = r - l + 1;
        vector<ll> ans(len+1, -INFLL);
        for(int i=0;i<(1<<len);i++){
            vector<int> ind;
            ll curr = 0;
            ll c = __builtin_popcount(i);
            for(int j=0;j<len;j++){
                if(i & (1<<j)){
                    curr += m * a[l + j];
                    ind.push_back(l + j);
                }
            }
            for(int i=0;i<c;i++){
                for(int j=0;j<c;j++){
                    ll mn = INF;
                    for(int x=min(ind[i], ind[j]);x<=max(ind[i], ind[j]);x++){
                        mn = min(mn, a[x]);
                    }
                    curr -= mn;
                }
            }
            ans[c] = max(ans[c], curr);
        }
        return ans;
    };*/
    function<vector<ll>(int, int)> solve = [&](int l, int r){
        //cout<<l<<" "<<r<<endl;
        if(l == r){ 
            return vector<ll>({0,m*a[l] - a[l]});
        }
        ll mn = INFLL, mnpos = -1;
        for(int i=l;i<=r;i++){
            if(a[i] <= mn){
                mn = a[i];
                mnpos = i;
            }
        }
        vector<ll> ans(r - l + 2, -INFLL);
        if(mnpos == l){
            auto v1 = solve(l+1, r);
            ans[0] = 0;
            for(int i=1;i<v1.size();i++){
                ans[i] = max(v1[i], v1[i-1] + m*a[mnpos] - (2*i - 1)*a[mnpos]);
            }
            assert(r - l < v1.size());
            ans[r-l+1] = v1[r-l] + m*a[mnpos] - (2*(r-l) + 1)*a[mnpos]; 
            //cout<<l<<" "<<r<<"\n";
            //cout+brute(l,r);
            //cout+ans;
            return ans;
        }
        if(mnpos == r){
            auto v1 = solve(l, r-1);
            ans[0] = 0;
            for(int i=1;i<v1.size();i++){
                ans[i] = max(v1[i], v1[i-1] + m*a[mnpos] - (2*i - 1)*a[mnpos]);
            }
            assert(r - l < v1.size());
            ans[r-l+1] = v1[r-l] + m*a[mnpos] - (2*(r-l) + 1)*a[mnpos]; 
            //cout<<l<<" "<<r<<"\n";
            //cout+brute(l,r);
            //cout+ans;
            return ans;
        }
        ans[0] = 0;
        auto v1 = solve(l, mnpos);
        auto v2 = solve(mnpos+1, r);
        assert(v1.size() - 1  + v2.size() - 1 < ans.size());
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                ans[i+j] = max(ans[i+j], v1[i] + v2[j] - 2*i*j*a[mnpos]);
            }
        }
        //cout<<l<<" "<<r<<"\n";
        //cout+brute(l,r);
        //cout+ans;
        return ans;
    };
    //cout+brute(0, n-1)<<"\n";
    cout<<solve(0,n-1)[m]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
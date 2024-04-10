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
const ll INF = 1e18;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> seq(n);
    vector<pair<int,ll>> obj(n);
    for(auto &v : seq){
        int s;
        cin>>s;
        v.resize(s);
        cin>>v;
    }
    for(int i=0;i<n;i++){
        auto &[wt,val] = obj[i];
        wt = seq[i].size();
        val = accumulate(seq[i].begin(), seq[i].end(), 0ll);
    }
    vector<ll> ans(n);
    function<void(int,int,const vector<ll>&)> knapsack = [&](int l,int r,const vector<ll>& prev){
        int mid = (l+r)/2;
        if(l+1 == r){
            ans[l] = prev[k];
            ll sum = 0;
            for(int i=k-1,j=0;i>=0 && j<seq[l].size();--i, ++j){
                sum+=seq[l][j];
                ans[l] = max(ans[l], prev[i] + sum);
            }
            return;
        }
        auto add = [&](const pair<int,ll> &object, vector<ll> &knap){
            const auto &[wt,val] = object;
            for(int i=k;i>=wt;--i){
                knap[i] = max(knap[i], knap[i-wt] + val);
            }
        };
        vector<ll> curr = prev;
        for(int i=l;i<mid;i++){
            add(obj[i], curr);
        }
        knapsack(mid,r,curr);
        curr = prev;
        for(int i=mid;i<r;i++){
            add(obj[i], curr);
        }
        knapsack(l,mid,curr);
    };
    vector<ll> dp(k+1, -INF);
    dp[0] = 0;
    knapsack(0,n,dp);
    //cout+ans;
    cout<<*max_element(ans.begin(), ans.end())<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
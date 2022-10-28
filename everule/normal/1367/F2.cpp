#include <iostream>
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
    int n;
    cin>>n;
    map<int,pair<int,int>> dp;
    map<int,int> idx;
    map<int,int> count;
    map<int,int> countof;
    map<int,int> delay;
    vector<int> seq(n);
    cin>>seq;
    vector<int> sortseq=seq;
    sort(sortseq.begin(), sortseq.end());
    for(int i=0;i<n;i++){
        countof[seq[i]]++;
        if(idx.count(sortseq[i])==0){
            idx[sortseq[i]]=i;
        }
    }
    for(int i=0;i<n;i++){
        ++dp[seq[i]].first;
        ++count[seq[i]];
        ++dp[seq[i]].second;
        if(idx[seq[i]]==0){
            continue;
        }
        if(count[seq[i]]==1){
            delay[seq[i]]=dp[sortseq[idx[seq[i]] - 1]].second;
        }
        dp[seq[i]].first =  max(dp[seq[i]].first, dp[sortseq[idx[seq[i]] - 1]].second + 1);
        if(count[seq[i]]==countof[seq[i]]){
            dp[seq[i]].second = delay[seq[i]] + count[seq[i]]; 
        }
    }
    int ans = n;
    for(const auto &x : dp){
        //cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<'\n';
        ans=min(ans, n - x.second.first);
    }
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
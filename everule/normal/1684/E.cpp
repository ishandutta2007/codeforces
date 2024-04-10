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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    cin>>a;
    map<int, int> cnt;
    for(auto &x : a) cnt[x]++;
    vector<int> cnts;
    for(auto &[x, cntx] : cnt){
        cnts.push_back(cntx);
    }
    sort(cnts.begin(), cnts.end());
    cnts.resize(unique(cnts.begin(), cnts.end()) - cnts.begin());
    vector<array<int, 2>> cntcnt(cnts.size());
    for(int i=0;i<cnts.size();i++) cntcnt[i] = {cnts[i], 0};
    for(auto &[x, cntx] : cnt){
        int idx = lower_bound(cnts.begin(), cnts.end(), cntx) - cnts.begin();
        cntcnt[idx][1]++;
    }
    int tot_distinct = cnt.size();
    int num_extra_distinct = 0;
    int ans = INF;
    for(int mex=0;mex<=n;mex++){
        int num_op = k;
        int num_less_distinct = 0;
        for(auto &[cnt, numcnt] : cntcnt){
            num_less_distinct += min(numcnt, num_op / cnt);
            num_op -= min(numcnt, num_op / cnt) * cnt;
        }
        ans = min(ans, tot_distinct + num_extra_distinct - num_less_distinct - mex);
        if(mex == n) break;
        if(cnt.count(mex)){
            cntcnt[lower_bound(cnts.begin(), cnts.end(), cnt[mex]) - cnts.begin()][1]--;
        }
        else{
            num_extra_distinct++;
        }
        if(k < num_extra_distinct){
            break;
        }
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
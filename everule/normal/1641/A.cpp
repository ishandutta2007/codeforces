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
void solve(){
    int n,x;
    cin>>n>>x;
    map<int, vector<int>> reps;
    for(int i=0;i<n;i++){
        int cnt = 0;
        int val;
        cin>>val;
        while(val % x == 0){
            val /= x;
            cnt++;
        }
        reps[val].push_back(cnt);
    }
    int ans = 0;
    for(auto &[_, v] : reps){
        sort(v.begin(), v.end(), greater<int>());
        vector<int> idk;
        for(auto &t : v){
            if(idk.size() > 0 && idk.back() == t + 1){
                idk.pop_back();
                continue;
            }
            idk.push_back(t);
        }
        ans += idk.size();
    }
    cout<<ans<<'\n';
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
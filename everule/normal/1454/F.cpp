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
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    map<int,vector<int>,greater<int>> mp;
    for(int i=0;i<n;i++) mp[seq[i]].push_back(i);
    int cnt = 0;
    int mn = 1e9;
    int mx = -1e9;
    for(const auto &[val,indices] : mp){
        if(cnt == 0){
            if(indices.size() >= 3){
                int idx = indices[1];
                cout<<"YES\n";
                cout<<idx<<" "<<1<<" "<<n-idx-1<<"\n";
                return;
            }
            cnt += indices.size();
            mn = min(mn, indices[0]);
            mx = max(mx, indices.back());
            continue;
        }
        auto it = lower_bound(indices.begin(), indices.end(), mn);
        int curr = cnt;
        while(it != indices.end() && *it < mx){
            ++curr;
            ++it;
        }
        if(curr == cnt){
            if(binary_search(indices.begin(), indices.end(), mn-1)){
                if(indices[0] < mn-1){
                    mn = mn - 1;
                    ++curr;
                }
            }
            if(binary_search(indices.begin(), indices.end(), mx + 1)){
                if(indices.back() > mx + 1){
                    mx = mx + 1;
                    ++curr;
                }
            }
        }
        if(curr == mx - mn + 1 && indices[0] < mn && indices.back() > mx && curr!=cnt){
            cout<<"YES\n";
            cout<<mn<<" "<<mx - mn + 1<<" "<<n - mx - 1<<"\n";
            return;
        }
        cnt += indices.size();
        mn = min(mn, indices[0]);
        mx = max(mx, indices.back());
    }
    cout<<"NO\n";
    return;
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
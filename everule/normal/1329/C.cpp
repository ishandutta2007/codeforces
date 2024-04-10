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
    int h,g;
    cin>>h>>g;
    int n = (1<<h) - 1;
    vector<int> seq(2*n + 2);
    for(int i=1;i<=n;i++) cin>>seq[i];
    vector<int> sz(n + 1);
    function<int(int)> calcsize = [&](int i){
        if(seq[i] == 0) return 0;
        sz[i] = calcsize(2*i) + calcsize(2*i + 1) + 1;
        return sz[i];
    };
    calcsize(1);
    vector<int> expsize(n + 1);
    function<int(int)> calcexpsize = [&](int i){
        if(i >= (1<<g)) return 0;
        expsize[i] = calcexpsize(2*i) + calcexpsize(2*i + 1) + 1;
        return expsize[i];
    };
    calcexpsize(1);
    //cout+sz+expsize;
    function<void(int)> f = [&](int i){
        --sz[i];
        if(seq[2*i] == 0 && seq[2*i + 1] == 0){
            seq[i] = 0;
            return;
        }
        if(seq[2*i] > seq[2*i + 1]){
            seq[i] = seq[2*i];
            f(2*i);
        }
        else{
            seq[i] = seq[2*i + 1];
            f(2*i + 1);
        }
    };
    function<bool(int)> safe = [&](int i){
        if(seq[2*i] == 0 && seq[2*i + 1] == 0){
            if(sz[i] == expsize[i]) return false;
            return true;
        } 
        if(seq[2*i] > seq[2*i + 1]){
            if(safe(2*i)){
                assert(sz[i] > expsize[i]);
                return true;
            }
            return false;
        }
        else{
            if(safe(2*i + 1)){
                assert(sz[i] > expsize[i]);
                return true;
            }
            return false;
        }
        return false;
    };
    vector<int> ans;
    ll tot = accumulate(seq.begin(), seq.end(), 0ll);
    for(int i=1;i<=n;i++) while(safe(i)){
        tot -= seq[i];
        f(i);
        ans.push_back(i);
    }
    cout<<tot<<"\n";
    cout+ans;
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
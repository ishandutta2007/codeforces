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
    vector<ll> fib(50);
    fib[0] = fib[1] = 1;
    for(int i=2;i<fib.size();i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    int k;
    cin>>k;
    vector<int> c(k);
    cin>>c;
    priority_queue<int> pq(c.begin(), c.end());
    ll sum = accumulate(c.begin(), c.end(), 0ll);
    int x = 0;
    while(sum > 0){
        sum -= fib[x++];
    }
    if(sum < 0){
        cout<<"NO\n";
        return;
    }
    int prev = -1;
    for(int i=x-1;i>=0;--i){
        int best_idx = -1; //technically only
        int best_val = -1;
        for(int j=0;j<k;j++){
            if(j != prev && best_val < c[j]){
                best_idx = j;
                best_val = c[j];
            }
        }
        if(best_val < fib[i]){
            cout<<"NO\n";
            return;
        }
        c[best_idx] -= fib[i];
        prev = best_idx;
    }
    cout<<"YES\n";
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
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
    int n,k;
    cin>>n>>k;
    if(n == 1){
        cout<<"ACCEPTED\n";
        return;
    }
    vector<vector<int>> ops(k);
    for(int i=0;i<k;i++){
        int q;
        cin>>q;
        ops[i].resize(q);
        cin>>ops[i];
        for(auto &x : ops[i]) --x;
        reverse(ops[i].begin(), ops[i].end());
    }
    auto f = [&](auto &&f, ll fixed_mask, ll swap_mask, int steps){
        if(steps == k){
            return (swap_mask == 0) && (__builtin_popcountll(fixed_mask + 1) == 1);
        }
        int min_0 = 0, max_0 = 0;
        for(auto &i : ops[steps]){
            if((swap_mask >> i) & 1) max_0++;
            else if((~fixed_mask >> i) & 1) min_0++;
        }
        max_0 += min_0;
        bool ans = 1;
        for(int num_0=min_0;num_0<=max_0;num_0++){
            ll nfixed_mask = fixed_mask, nswap_mask = swap_mask;
            for(int j=0;j<ops[steps].size();j++){
                int b = ops[steps][j];
                nswap_mask &= ~(1ll<<b);
                if(j < num_0) nfixed_mask &= ~(1ll<<b);
                else nfixed_mask |= (1ll<<b);
            }
            //cout<<nfixed_mask<<" "<<nswap_mask<<"\n";
            //cout<<bitset<4>(nfixed_mask)<<" "<<bitset<4>(nswap_mask)<<"\n";
            ans &= f(f, nfixed_mask, nswap_mask, steps + 1);
        }
        return ans;
    };
    ll fixed_mask = 0;
    ll swap_mask = (1ll<<n) - 1;
    bool is_valid = f(f, fixed_mask, swap_mask, 0);
    if(is_valid){
        cout<<"ACCEPTED\n";
    }
    else{
        cout<<"REJECTED\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
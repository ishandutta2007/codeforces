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
const int INF = 1e9;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> cnt(1<<k);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    vector<int> pcnt((1<<k) + 1);
    for(int i=1;i<=(1<<k);i++) pcnt[i] = pcnt[i-1] + cnt[i-1];
    function<int(int,int,int)> getSmallest = [&](int l,int r, int x){
        int mid = (l + r) / 2;
        int bit = __builtin_ctz(r - l) - 1;
        if(bit == -1) return l;
        if(x & (1<<bit)){
            if(pcnt[r] - pcnt[mid] > 0){
                return getSmallest(mid, r, x & ((1<<bit) - 1));
            }
            else{
                return getSmallest(l, mid, x & ((1<<bit) - 1));
            }
        }
        else{
            if(pcnt[mid] - pcnt[l] == 0){
                return getSmallest(mid, r, x & ((1<<bit) - 1));
            }
            else{
                return getSmallest(l, mid, x & ((1<<bit) - 1));
            }
        }
        return -1;
    };
    vector<vector<int>> bst(k, vector<int>(1<<k, INF));
    function<void(int,int)> dnc = [&](int l,int r){
        int bit = __builtin_ctz(r - l);
        if(bit == 0){
            return;
        }
        int mid = (l + r) / 2;
        if(pcnt[r] == pcnt[l]){
            return;
        }
        dnc(l, mid);
        dnc(mid, r);
        if(pcnt[l] == pcnt[mid] || pcnt[mid] == pcnt[r]){
            return;
        }
        for(int x=0;x<(1<<bit);x++){
            if(~x & (1<<(bit-1))){
                int lm = getSmallest(l, mid, ~x) ^ x;
                int rm = getSmallest(mid, r, x) ^ x;
                bst[bit-1][x] = min(bst[bit-1][x], rm - lm);
            }
            else{
                int lm = getSmallest(l, mid, x) ^ x;
                int rm = getSmallest(mid, r, ~x) ^ x;
                bst[bit-1][x] = min(bst[bit-1][x], lm - rm);
            }
        }
    };
    dnc(0, (1<<k));
    //cout*bst;
    for(int i=0;i<(1<<k);i++){
        int ans = INF;
        for(int j=0;j<k;j++){
            ans = min(ans, bst[j][i & ((1<<(j+1)) - 1)]);
        }
        cout<<ans<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
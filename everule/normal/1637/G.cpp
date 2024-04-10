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
    if(n == 2){
        cout<<"-1\n";
        return;
    }
    int max_pow = 1;
    while(max_pow < n) max_pow *= 2;
    vector<array<int, 2>> ops;
    vector<int> cnt(__builtin_ctz(max_pow) + 1);
    function<void(int, int)> dnc = [&](int r, int mult){
        if(r == 0) return;
        if(r <= 2){
            cnt[__builtin_ctz(mult)]++;
            if(r == 2) cnt[__builtin_ctz(mult) + 1]++;
            return;
        }
        if(__builtin_popcount(r) == 1){
            cnt[__builtin_ctz(r * mult)]++;
            dnc(r - 1, mult);
            return;
        }
        int cmax_pow = 1;
        while(cmax_pow < r) cmax_pow *= 2;
        int l = cmax_pow - r;
        dnc(l - 1, mult);
        int num_value = (r - l) / 2;
        cnt[__builtin_ctz(cmax_pow * mult)] += num_value;
        while(l < r){
            ops.push_back({l * mult, r * mult});
            l++;
            r--;
        }
        dnc(num_value, mult * 2);
        if(l == r){
            assert(__builtin_popcount(l) == 1);
            cnt[__builtin_ctz(l * mult)]++;
        }
    };
    dnc(n, 1);
    for(int i=0;i+1<cnt.size();i++){
        if(cnt[i] > 1){
            ops.push_back({(1<<i), (1<<i)});
            cnt[i] -= 2;
            cnt[i+1] += 1;
            break;
        }
    }
    for(int i=0;i+1<cnt.size();i++){
        while(cnt[i] > 0){
            ops.push_back({(1<<i), 0});
            ops.push_back({(1<<i), (1<<i)});
            cnt[i] -= 1;
            cnt[i+1] += 1;
        }
    }
    ops.push_back({max_pow, 0});
    cout<<ops.size()<<"\n";
    multiset<int> ms;
    for(int i=1;i<=n;i++) ms.insert(i);
    for(auto &[x, y] : ops){
        ms.erase(ms.find(x));
        ms.erase(ms.find(y));
        ms.insert(x+y);
        ms.insert(abs(x-y));
    }
    assert(*ms.begin() == *ms.rbegin());
    for(auto &[x, y] : ops) cout<<x<<" "<<y<<"\n";
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
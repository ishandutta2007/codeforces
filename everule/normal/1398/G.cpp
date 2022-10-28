#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl

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
const int MAXA = 2e5 + 7;
const int MAXQ = 1e6 + 7;
void solve(){
    bitset<MAXA + 1> arr;
    bitset<MAXA + 1> ans;
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> seq(n+1);
    for(int i=0;i<=n;i++){
        cin>>seq[i];
        arr[seq[i]] = 1;
    }
    for(int i=0;i<n;i++){
        ans|=arr>>seq[i];
    }
    vector<int> fin(MAXQ,-1);
    for(int i=1;i<=MAXA;i++){
        if(!ans[i]) continue;
        int k = 2*i + 2*y;
        for(int j=k;j<=MAXQ;j+=k){
            fin[j] = k;
        }
    }
    int m;
    cin>>m;
    while(m--){
        int l;
        cin>>l;
        cout<<fin[l]<<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
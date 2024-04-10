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
    vector<int> seq1(n), seq2(n);
    cin>>seq1>>seq2;

    reverse(seq2.begin(), seq2.end());

    map<int, int> m;
    m[0] = n;
    for(int i=0, x=0;i<n;i++){
        if(seq1[i]==1){
            ++x;
        }
        else{
            --x;
        }
        int j = n - i - 1;
        m[x] = j;
    }
    int ans = n + m[0];
    for(int i=0,x =0;i<n;i++){
        int j = n-1-i;
        if(seq2[i]==1){
            ++x;
        }
        else{
            --x;
        }
        if(m.count(-x)){
            ans = min(ans, m[-x] + j);
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
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
    vector<int> seq(n);
    cin>>seq;
    int sum = accumulate(seq.begin(), seq.end(), 0);
    if(sum==0){
        cout<<"NO\n";
        return;
    }
    int psum=0, nsum=0;
    for(const auto &x : seq){
        if(x > 0){
            psum+=x;
        }
        else{
            nsum-=x;
        }
    }
    sort(seq.begin(), seq.end());
    if(psum > nsum){
        reverse(seq.begin(), seq.end());
    }
    cout<<"YES\n";
    cout+seq;
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
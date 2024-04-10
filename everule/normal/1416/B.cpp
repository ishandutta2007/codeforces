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
    if(sum%n!=0){
        cout<<"-1\n";
        return;
    }
    vector<array<int,3>> ops;
    function<void(int,int,int)> op = [&](int i,int j,int x){
        ops.push_back({i,j,x});
        seq[i]-=x*(i+1);
        seq[j]+=x*(i+1);
        assert(seq[i]>=0);
        assert(seq[j]>=0);
    };
    for(int i=1;i<n;i++){
        if(seq[i]%(i+1)!=0){
            op(0,i,i+1-seq[i]%(i+1));
        }
        op(i,0,seq[i]/(i+1));
    }
    for(int i=1;i<n;i++){
        op(0,i,sum/n);
    }
    assert(ops.size()<=3*n);
    cout<<ops.size()<<"\n";
    for(const auto &[i,j,x] : ops){
        cout<<i+1<<" "<<j+1<<" "<<x<<"\n";
    }
    //cout+seq;
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
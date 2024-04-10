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
    vector<int> a(n);
    cin>>a;
    if(n == 2){
        cout<<a[1] - a[0]<<"\n";
        return;
    }
    auto do_op = [&](){
        vector<int> b(a.size()-1);
        for(int i=1;i<a.size();i++) b[i-1] = a[i] - a[i-1];
        sort(b.begin(), b.end());
        a = b;
    };
    /*
    while(a.size() > 1){
        do_op();
        cout+a;
    }
    cout<<a[0]<<"\n";
    */
    do_op();
    do_op();
    int cnt_0 = 0;
    vector<int> nz;
    for(auto &x : a){
        if(x == 0) cnt_0++;
        else nz.push_back(x);
    }
    assert(nz.size() <= 1000);
    auto do_compress_op = [&](){
        if(nz.size() == 0){
            cnt_0 = 1;
            return;
        }
        vector<int> nnz(nz.size() - 1);
        for(int i=1;i<nz.size();i++) nnz[i-1] = nz[i] - nz[i-1];
        if(cnt_0 > 0){
            nnz.push_back(nz[0]);
            cnt_0--;
        }
        nz = nnz;
        sort(nz.begin(), nz.end());
    };
    while(cnt_0 + nz.size() > 1){
        do_compress_op();
    }
    cout<<(cnt_0 > 0 ? 0 : nz[0])<<"\n";
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
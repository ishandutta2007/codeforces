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
    int cnt = 0;
    auto conv = [&](pair<int,int> o){
        cout<<o.first + 1<<" "<<o.second + 1<<"\n";
    };
    vector<pair<int,int>> o,e;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i + j) % 2) o.emplace_back(i,j);
            else e.emplace_back(i,j);
        }
    }
    for(;cnt<n*n;cnt++){
        int a;
        cin>>a;
        if(a == 1){
            cout<<2<<" ";
            conv(e.back());
            e.pop_back();
        }
        else{
            cout<<1<<" ";
            conv(o.back());
            o.pop_back();
        }
        if(e.empty()) break;
        if(o.empty()) break;
    }
    for(;cnt<n*n;cnt++){
        int a;
        cin>>a;
        if(o.size()){
            if(a == 1){
                cout<<3<<" ";
                conv(o.back());
                o.pop_back();
            }
            else{
                cout<<1<<" ";
                conv(o.back());
                o.pop_back();
            }
        }
        if(e.size()){
            if(a == 2){
                cout<<3<<" ";
                conv(e.back());
                e.pop_back();
            }
            else{
                cout<<2<<" ";
                conv(e.back());
                e.pop_back();
            }
        }
    }
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    solve();
}
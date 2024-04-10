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
    vector<int> odd,even;
    for(int i=0;i<2*n;i++){
        int x;
        cin>>x;
        if(x&1){
            odd.pb(i+1);
        }
        else{
            even.pb(i+1);
        }
    }
    int a= odd.size(),b = even.size();
    if(b&1){
        even.pop_back();
        odd.pop_back();
        for(int i=0;i<odd.size();i+=2){
            cout<<odd[i]<<" "<<odd[i+1]<<"\n";
        }
        for(int i=0;i<even.size();i+=2){
            cout<<even[i]<<" "<<even[i+1]<<"\n";
        }
    }
    else{
        int count=0;
        for(int i=0;i<odd.size();i+=2){
            if(count<n-1){
                cout<<odd[i]<<" "<<odd[i+1]<<"\n";
                ++count;
            }
        }
        for(int i=0;i<even.size();i+=2){
            if(count<n-1){
                cout<<even[i]<<" "<<even[i+1]<<"\n";
                ++count;
            }
        }
    }
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
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
    for(int i=0;i<n;i++){
        int d = i - 1;
        for(int j=0;j<n;j++){
            if(i&1){
                cout<<(1ll<<(d+j))<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        bool last = 0;
        int i=1,j=1;
        cout<<i<<" "<<j<<"\n";
        for(int s=1;s<2*n - 1;s++){
            if(last ^ (k&1)){
                i++;
                cout<<i<<" "<<j<<"\n";
            }
            else{
                j++;
                cout<<i<<" "<<j<<"\n";
            }
            last = k&1;
            k>>=1;
        }
        cout.flush();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    solve();
}
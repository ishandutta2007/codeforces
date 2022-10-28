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
const int bits = 10;
void solve(){
    vector<bool> ans0(bits);
    vector<bool> ans1(bits, 1);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char type;
        int val;
        cin>>type>>val;
        for(int j=0;j<bits;j++){
            bool set = (val>>j)&1;
            if(type=='&'){
                ans0[j] = ans0[j]&set;
                ans1[j] = ans1[j]&set;
            }
            if(type=='|'){
                ans0[j] = ans0[j]|set;
                ans1[j] = ans1[j]|set;
            }
            if(type=='^'){
                ans0[j] = ans0[j]^set;
                ans1[j] = ans1[j]^set;
            }
        }
    }
    int fin1=0, fin2=0;
    for(int i=0;i<bits;i++){
        if(ans0[i]!=ans1[i]){
            fin1|=(1<<i);
        }
        if(ans0[i]!=0){
            fin2|=(1<<i);
        }
    }
    cout<<"2\n";
    cout<<"& "<<fin1<<"\n";
    cout<<"^ "<<fin2<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
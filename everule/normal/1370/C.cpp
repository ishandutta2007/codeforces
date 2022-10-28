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
bool checkprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
bool solve(){
    int n;
    cin>>n;
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(__builtin_popcount(n)==1){
        return 0;
    }
    if(n&1){
        return 1;
    }
    int pow = __builtin_ctz(n);
    n>>=pow;
    if(pow>1){
        return 1;
    }
    if(checkprime(n)){
        return 0;
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout<<"Ashishgup\n";
        }
        else{
            cout<<"FastestFinger\n";
        }
    }
}
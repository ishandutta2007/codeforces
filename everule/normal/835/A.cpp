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
    int s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int x = s*v1 + 2*t1;
    int y = s*v2 + 2*t2;
    if(x==y){
        cout<<"Friendship\n";
    }
    if(x<y){
        cout<<"First\n";
    }
    if(x>y){
        cout<<"Second\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
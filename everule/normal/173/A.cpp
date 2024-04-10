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
int beat(char a, char b){
    if(a=='S' && b=='P' || a=='P' && b=='R' || a=='R' && b=='S'){
        return 1;
    }
    return 0;
}
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int tl = s.size()*t.size()/__gcd(s.size(),t.size());
    string a,b;
    while(a.size() < tl){
        a+=s;
    }
    while(b.size() < tl){
        b+=t;
    }
    vector<int> p1(tl+1), p2(tl+1);
    for(int i=1;i<=tl;i++){
        p1[i] = p1[i-1];
        p2[i] = p2[i-1];
        if(beat(a[i-1], b[i-1])){
            p1[i]++;
        }
        if(beat(b[i-1], a[i-1])){
            p2[i]++;
        }
    }
    int rem = n%tl;
    cout<<n/tl * p2[tl] + p2[rem]<<" "<<n/tl * p1[tl] + p1[rem]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
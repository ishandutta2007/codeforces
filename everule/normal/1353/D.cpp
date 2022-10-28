//https://codeforces.com/contest/1353/problem/D
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
struct segment{
    int l,r;
};
bool operator<(const segment &x, const segment &y){
    return ((x.r-x.l==y.r-y.l) ? x.l<y.l : x.r-x.l>y.r-y.l);
}
segment make_segment(int l,int r){
    segment curr;
    curr.l=l;
    curr.r=r;
    return curr;
}
istream& operator>>(istream & in, segment &s){
    cin>>s.l>>s.r;
    return in;
}
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
    set<segment> segments;
    vector<int> seq(n, -1);
    segments.insert(make_segment(0,n-1));
    int count=0;
    while(segments.size()){
        int l=(*segments.begin()).l;
        int r=(*segments.begin()).r;
        int idx=l+r;
        idx>>=1;
        seq[idx]=++count;
        segments.erase(segments.begin());
        if(l==r){
            continue;
        }
        segments.insert(make_segment(idx+1, r));
        if(l==idx){
            continue;
        }
        segments.insert(make_segment(l,idx-1));
    }    
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
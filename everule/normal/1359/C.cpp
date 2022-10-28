#pragma GCC optimize "trapv"
//https://codeforces.com/contest/1359/problem/C
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define int long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
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
struct fraction{
    int num, denom;
    fraction(int num, int denom) : num(num), denom(denom){

    }
    bool operator<(fraction o){
        return num*o.denom < denom*o.num;
    }
    fraction operator-(int x){
        return fraction(num - x*denom, denom);
    }
    bool operator==(fraction o){
        return num==o.num && denom ==o.denom;
    }
};
fraction pos(const fraction &x){
    return fraction(std::abs(x.num), std::abs(x.denom));
}
void solve(){
    int h,c,t;
    cin>>h>>c>>t;
    h-=c;
    t-=c;
    auto convert = [&](int x){
        return mp(pos(fraction((x+1)*h, 2*x + 1) - t), x);
    };
    vector<pair<fraction, int>> answers;
    if((2*t - h)<=0){
        cout<<2<<"\n";
        return;
    }
    int ans = (h-t)/(2*t - h);
    answers.pb(convert(ans));
    answers.pb(convert(ans+1));
    sort(answers.begin(), answers.end(), [&](pair<fraction, int> x,  pair<fraction, int> y){
        return x.first==y.first ? x.second < y.second : x.first<y.first;
    });
    cout<<2*answers[0].second + 1<<"\n";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
//https://codeforces.com/contest/1354/problem/C1
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
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
const long double pi = 3.141592653589793238;
const long double root2=1.41421356237309504880;
long double formula(int n){
    int k=n-2;
    k/=4;
    long double t=pi/n;
    long double ans=2;
    ans*=sin((k+1)*t/2)/sin(t/2);
    ans*=sin(pi/4 - (k+1)*t/2);
    ans+=1/sin(t/2)/root2;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fixed<<setprecision(12)<<formula(n)<<"\n";
    }
}
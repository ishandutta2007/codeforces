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
struct node{
    ll value, sum;
    int idx;
};
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    stack<node> blocks;
    node init;
    init.idx=-1;
    init.sum=0;
    init.value=-1;
    blocks.push(init);
    vector<ll> dpforward(n);
    for(int i=0;i<n;i++){
        node topush;
        topush.idx=i;
        topush.value=seq[i];
        while(blocks.top().value>=topush.value){
            blocks.pop();
        }
        topush.sum=(i-blocks.top().idx)*topush.value + blocks.top().sum;
        blocks.push(topush);
        dpforward[i]=blocks.top().sum;
    }
    while(!blocks.empty()){
        blocks.pop();
    }
    init.idx=n;
    blocks.push(init);
    vector<ll> dpbackward(n);
    for(int i=n-1;i>=0;--i){
        node topush;
        topush.idx=i;
        topush.value=seq[i];
        while(blocks.top().value>=topush.value){
            blocks.pop();
        }
        topush.sum=(blocks.top().idx - i)*topush.value + blocks.top().sum;
        blocks.push(topush);
        dpbackward[i]=blocks.top().sum;
    }
    ll ans=0;
    int anspeak=-1;
    for(int i=0;i<n;i++){
        if(dpforward[i] + dpbackward[i] - seq[i] > ans){
            ans=dpforward[i] + dpbackward[i] - seq[i];
            anspeak=i;
        }
    }
    while(!blocks.empty()){
        blocks.pop();
    }
    init.idx=-1;
    blocks.push(init);
    for(int i=0;i<=anspeak;i++){
        node topush;
        topush.idx=i;
        topush.value=seq[i];
        while(blocks.top().value>=topush.value){
            blocks.pop();
        }
        topush.sum=(i-blocks.top().idx)*topush.value + blocks.top().sum;
        blocks.push(topush);
    }
    vector<int> height(n);
    while(!blocks.empty()){
        int start=blocks.top().idx;
        int val=blocks.top().value;
        blocks.pop();
        if(blocks.empty()){
            break;
        }
        for(int i=start;i>blocks.top().idx;--i){
            height[i]=val;
        }
    }
    init.idx=n;
    blocks.push(init);
    for(int i=n-1;i>=anspeak;--i){
        node topush;
        topush.idx=i;
        topush.value=seq[i];
        while(blocks.top().value>=topush.value){
            blocks.pop();
        }
        topush.sum=(blocks.top().idx - i)*topush.value + blocks.top().sum;
        blocks.push(topush);
    }
    while(!blocks.empty()){
        int start=blocks.top().idx;
        int val=blocks.top().value;
        blocks.pop();
        if(blocks.empty()){
            break;
        }
        for(int i=start;i<blocks.top().idx;i++){
            height[i]=val;
        }
    }
    cout+height;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
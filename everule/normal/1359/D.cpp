//https://codeforces.com/contest/1359/problem/D
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
struct node{
    int val;
    int pref;
    int idx;
    node(int val, int idx, int pref) : val(val), idx(idx), pref(pref){}
};
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    for(auto &x : seq){
        cin>>x;
    }
    vector<int> prefixsum(n+1, 0);
    for(int i=1;i<=n;i++){
        prefixsum[i]=prefixsum[i-1]+seq[i-1];
    }
    vector<ll> ans(n);
    stack<node> values;
    for(int i=0;i<n;i++){
        node curr(seq[i], i, prefixsum[i]);
        while(!values.empty() && values.top().val<=curr.val){
            curr.pref=min(curr.pref, values.top().pref);
            values.pop();
        }
        values.push(curr);
        ans[i]-=curr.pref;
    }
    while(!values.empty()){
        values.pop();
    }
    cout<<"\n";
    for(int i=n-1;i>=0;--i){
        node curr(seq[i], i, prefixsum[i+1]);
        while(!values.empty() && values.top().val<=curr.val){
            curr.pref=max(curr.pref, values.top().pref);
            values.pop();
        }
        ans[i]+=curr.pref;
        values.push(curr);
    }
    ll finans=-1;
    for(int i=0;i<n;i++){
        finans=max(ans[i]-seq[i], finans);
    }
    cout<<finans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
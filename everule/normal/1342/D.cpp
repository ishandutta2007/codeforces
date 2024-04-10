//https://codeforces.com/contest/1342/problem/D
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
        out<<x.size()<<" ";
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
    int n,k;
    cin>>n>>k;
    vector<int> freq(k);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        --x;
        ++freq[x];
    }
    vector<int> c(k);
    cin>>c;
    int mn=1, mx=n;
    while(mn<mx){
        int mid=mn+mx;
        mid>>=1;
        int curr=1e9, rem=0;
        for(int i=0;i<k;++i){
            if(curr>c[i]){
                curr=c[i];
                rem=0;
            }
            rem+=freq[i]%mid;
            curr-=freq[i]/mid;
            if(rem>=mid){
                rem-=mid;
                --curr;
            }
        }
        if(curr<0 || (curr==0 && rem>0)){
            mn=mid+1;
        }
        else{
            mx=mid;
        }
    }
    cout<<mn<<'\n';
    int curr=1e9, rem=0;
    vector<vector<int>> ans(mn);
    for(int i=0, j=0;i<k;++i){
        if(curr>c[i]){
            curr=c[i];
            rem=0;
        }
        for(int l=0;l<freq[i]/mn;l++){
            for(int s=0;s<mn;s++){
                ans[s].pb(i+1);
            }
        }
        rem+=freq[i]%mn;
        int count=freq[i]%mn;
        curr-=freq[i]/mn;
        while(count--){
            ans[j%mn].pb(i+1);
            ++j;
        }
        if(rem>=mn){
            rem-=mn;
            --curr;
        }
    }
    cout*ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
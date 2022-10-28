//#pragma GCC optimize "trapv"
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
struct subjects{
    ll a;
    ll calcincrease(ll b){
        return a - 3*b*b - 3*b - 1;
    }
    ll getmax(ll A){
        int mn=0, mx=a;
        while(mn<mx){
            int mid=mn+mx+1;
            mid>>=1;
            if(calcincrease(mid)>=A){
                mn=mid;
            }
            else{
                mx=mid-1;
            }
        }
        return mn;
    }
};
istream& operator>>(istream& in,subjects &x){
    cin>>x.a;
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
    ll n, k;
    cin>>n>>k;
    vector<subjects> type(n);
    cin>>type;
    ll mn=-4e18;ll mx=4e18;
    while(mn<mx){
        ll mid=mn+mx+1;
        mid>>=1;
        ll mink=0;
        ll maxk=0;
        vector<bool> iscurr(n);
        vector<ll> ans(n);
        for(int i=0;i<n;i++){
            ll x=type[i].getmax(mid);
            ll y=type[i].getmax(mid+1);
            if(x!=y){
                assert((x-y)==1);
                iscurr[i]=1;
            }
            ans[i]=y;
            mink+=y;
            maxk+=x;
        }
        assert(mink<=maxk);
        if(mink<=k && k<=maxk){
            ll needed=k-mink;
            for(int i=0;i<n;i++){
                if(needed && iscurr[i]){
                    cout<<ans[i]+1<<" ";
                    --needed;
                }
                else{
                    cout<<ans[i]<<" ";
                }
            }
            return;
        }
        if(k>maxk){
            mx=mid-1;
        }
        else{
            mn=mid;
        }
    }
    cout<<"-1\n";
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
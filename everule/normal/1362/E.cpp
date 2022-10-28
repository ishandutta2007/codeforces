//https://codeforces.com/contest/1362/problem/E
#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define int long long
const int MAXK = 1e6 + 7;
using namespace std;
int MEX(vector<int> &x){
    vector<bool> found(x.size());
    for(int i=0;i<x.size();i++){
        if(x[i]<x.size()){
            found[x[i]]=1;
        }
    }
    for(int i=0;i<x.size();i++){
        if(!found[i]){
            return i;
        }
    }
    return x.size();
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
const int mod =1e9 + 7;
int modpower(int base, int power, int mod=mod){
    int ans =1;
    base%=mod;
    while(power){
        if(power&1){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        power>>=1;
    }
    return ans;
}
void solve(){
    int n,p;
    cin>>n>>p;
    vector<int> seq(n);
    vector<int> val(n);
    for(int i=0;i<n;i++){
        cin>>seq[i];
    }
    if(p==1){
        cout<<(n&1)<<"\n";
        return;
    }
    vector<int> powers;
    powers.pb(1);
    while(powers.back()*p<4*MAXK){
        powers.pb(powers.back()*p);
    }
    sort(seq.begin(), seq.end(), greater<int>());
    for(int i=0;i<n;i++){
        val[i]=modpower(p, seq[i]);
    }
    for(int i=0;i<n;i++){
        int needed=1;
        int idx=i;
        for(i=i+1;i<n && (seq[i-1]-seq[i])<(int)powers.size();i++){
            needed*=powers[seq[i-1]-seq[i]];
            if(needed>4*MAXK){
                int difference=val[idx];
                for(int it=idx+1;it<n;it++){
                    difference+=mod-val[it];
                }
                difference%=mod;
                cout<<difference<<"\n";
                return;
            }
            --needed;
            if(!needed){
                break;
            }
        }
        if(needed){
            int difference=val[idx];
            for(int it=idx+1;it<n;it++){
                difference+=mod-val[it];
            }
            cout<<difference%mod<<"\n";
            return;
        }
    }
    cout<<"0\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
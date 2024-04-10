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
int query(const vector<int> &indices){
    cout<<"? "<<indices.size()<<" ";
    for(const auto &indice : indices){
        cout<<indice<<" ";
    }
    cout<<endl;
    int ans;
    cin>>ans;
    return ans;
}
int query(int l, int r){
    assert(r>=l);
    cout<<"? "<<r - l + 1<<" ";
    for(int i=l;i<=r;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    int ans;
    cin>>ans;
    return ans;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> subsets(k);
    vector<int> setof(n + 1, -1);
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        while(c--){
            int x;
            cin>>x;
            setof[x]=i;
            subsets[i].pb(x);
        }
    }
    int maxvalue = query(1,n);
    int maxidx;
    for(int mn=1,mx=n;mn<mx;){
        int mid = mx + mn;
        mid>>=1;
        if(maxvalue == query(mn, mid)){
            mx = mid;
        }
        else{
            mn = mid + 1;
        }
        maxidx=mn;
    }
    vector<int> ans(k, maxvalue);
    if(setof[maxidx]==-1){
        cout<<"! ";
        cout+ans;
        cout.flush();
        string s;
        cin>>s;
        assert(s=="Correct");
        return;
    }
    vector<int> queryidx;
    queryidx.reserve(n-subsets[setof[maxidx]].size());
    for(int i=1;i<=n;i++){
        if(setof[i]==setof[maxidx]){
            continue;
        }
        queryidx.pb(i);
    }
    ans[setof[maxidx]]=query(queryidx);
    cout<<"! ";
    cout+ans;
    cout.flush();
    string s;
    cin>>s;
    assert(s=="Correct");
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
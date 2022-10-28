#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
using ull = unsigned long long;
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
    vector<int> d1(n);
    cin>>d1;
    int m;
    cin>>m;
    vector<int> d2(m);
    cin>>d2;
    vector<int> d;
    d.reserve(n+m);
    for(int i=n,j=m, curr=0;i>0 || j>0;){
        while(i>0 && d1[i-1]==curr){
            d.pb(i);
            --i;
        }
        while(j>0 && d2[j-1]==curr){
            d.pb(n+j);
            --j;
        }
        curr^=1;
    }
    reverse(d.begin(), d.end());
    cout+d;
    vector<int> ans;
    for(int i=0;i<n+m;i++){
        if(d[i] <= n){
            d[i] = d1[d[i]-1];
        }
        else{
            d[i] = d2[d[i]-n-1];
        }
    }
    for(int i=1;i<n+m;i++){
        if(d[i]!=d[i-1]){
            ans.pb(i);
        }
    }
    if(d[n+m-1]==1){
        ans.pb(n+m);
    }
    cout<<ans.size()<<"\n";
    cout+ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
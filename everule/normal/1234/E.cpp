#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
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
struct Rangeadd{
    int l,r,val;
    Rangeadd(int l,int r,int val) : l(l), r(r), val(val) {}
    Rangeadd(){}
};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> seq(m);
    cin>>seq;
    vector<ll> ans(n);
    vector<Rangeadd> rad1;
    for(int i=1;i<m;i++){
        int a = seq[i];
        int b = seq[i-1];
        --a;--b;
        if(a==b) continue;
        if(a > b) swap(a,b);
        ans[a]+=b;
        ans[b]+=a+1;
        if(a > 0) rad1.emplace_back(0,a-1,b-a);
        if(b-a > 1) rad1.emplace_back(a+1,b-1,b-a-1);
        if(b+1 < n) rad1.emplace_back(b+1,n-1,b-a);
    }
    vector<Rangeadd> rad2 = rad1;
    sort(rad1.begin(), rad1.end(), [&](const Rangeadd &x, const Rangeadd &y){
        return x.l < y.l;
    });
    sort(rad2.begin(), rad2.end(), [&](const Rangeadd &x, const Rangeadd &y){
        return x.r < y.r;
    });
    for(ll i=0,j=0,k=0,offset=0;i<n;i++){
        while(j<rad1.size() && rad1[j].l<=i){
            offset+=rad1[j].val;
            ++j;
        }
        while(k < rad2.size() && rad2[k].r < i){
            offset-=rad2[k].val;
            ++k;
        }
        ans[i]+=offset;
    }
    cout+ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
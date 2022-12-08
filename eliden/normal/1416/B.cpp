#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<x<<endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n;
        cin>>n;
        ll sum=0;
        vector<ll> a(n+1);
        rep(i,0,n) {
            cin>>a[i+1];
            sum+=a[i+1];
        }
        //debug(sum);
        if(sum%n!=0) {
            cout<<"-1\n";
            continue;
        }
        vector<tuple<int,int,ll>> ops;
        auto doit =
            [&](int i,int j, ll x) {
                assert(1<= i && 1<=j && 0<=x && i<=n && j<=n && i!=j);
                ops.emplace_back(i,j,x);
                a[i] -= i*x;
                a[j] += i*x;
            };
        rep(j,2,n+1) if(a[j]>0) {
            if(a[j]%j!=0) {
                ll rem = j-(a[j]%j);
                doit(1,j,rem);
            }
            doit(j,1,a[j]/j);
        }
        ll b=sum/n;
        rep(j,2,n+1) doit(1,j,b);
        cout<<ops.size()<<"\n";
        for(const auto &tup:ops) {
            int i,j;
            ll x;
            tie(i,j,x) = tup;
            cout<<i<<" "<<j<<" "<<x<<"\n";
        }
    }
}
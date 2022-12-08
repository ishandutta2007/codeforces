#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
using ll = long long;
using vi = vector<int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    vi n(k);
    vector<tuple<ll,int,int>> sums;
    rep(i,0,k) {
        cin >> n[i];
        vi a(n[i]);
        rep(j,0,n[i]) cin >> a[j];
        ll sum=0;
        rep(j,0,n[i]) sum+= a[j];
        rep(j,0,n[i]) {
            sums.emplace_back(sum-a[j],i,j);
        }
    }
    sort(all(sums));
    int m=sz(sums);
    int i=0;
    ll a1=-1, a2=-1;
    int b1=-1, b2=-1;
    while(i<m) {
        ll sum = get<0>(sums[i]);
        int id=get<1>(sums[i]);
        int bb=get<2>(sums[i]);
        while(i+1<m && get<0>(sums[i+1])==sum) {
            ++i;
            if(get<1>(sums[i])!=id) {
                a1 = id;
                a2 = get<1>(sums[i]);
                b1 = bb;
                b2 = get<2>(sums[i]);
            }
        }
        ++i;
    }
    if(a1==-1) cout<<"NO\n";
    else {
        cout << "YES\n";
        cout << a1+1 <<" "<<b1+1<<"\n"<<a2+1<<" "<<b2+1<<"\n";
    }
}
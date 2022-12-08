#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) {
        ll x;
        cin >> x;
        int nbits=0;
        while(x) {
            if(x&1) ++nbits;
            x/=2;
        }
        a[i]=nbits;
        //debug(a[i]);
    }
    vi b(n);
    b[0]=a[0];
    rep(i,1,n) b[i]=b[i-1]+a[i];
    vi numeven(n+1), numodd(n+1);
    for(int i=n-1;i>=0;--i) {
        int even = b[i]%2==0;
        int odd = b[i]%2==1;
        numeven[i] = numeven[i+1]+even;
        numodd[i]=numodd[i+1]+odd;
    }
    const int M=70;
    ll tot=0;
    rep(i,0,n) {
        int acmax=0;
        ll acsum=0;
        rep(j,i,min(n,i+M)) {
            acsum+=a[j];
            acmax=max(acmax,a[j]);
            if(acsum%2==0 && acmax<=acsum-acmax) ++tot;
        }
        // test i+M onwards
        if(i+M<n) {
            ll leftsum=0;
            if(i>0) leftsum=b[i-1];
            if(leftsum%2==0) tot+=numeven[i+M];
            else tot+=numodd[i+M];
        }
    }
    cout << tot << endl;
}
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
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    int maxa=0;
    rep(i,0,n) maxa=max(maxa,a[i]);
    int k = maxa-1;
    bool works=false;
    while(!works) {
        ++k;
        int sum=0;
        rep(i,0,n) sum+=k-a[i]-a[i];
        works = sum>0;
    }
    cout<<k<<endl;
}
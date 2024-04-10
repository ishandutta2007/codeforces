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
    rep(i,0,n) cin >> a[i];
    sort(all(a));
    int sum=0;
    rep(i,0,n) sum+=a[i];
    int req = (9*n+1)/2;
    int i=0;
    while(sum<req) {
        sum+=5-a[i];
        ++i;
    }
    cout<<i<<"\n";
}
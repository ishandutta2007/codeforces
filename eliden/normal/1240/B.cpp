#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<"@"<<__LINE__<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    rep(test,0,tests) {
        int n;
        cin >> n;
        vi a(n);
        rep(i,0,n) cin >> a[i];
        set<int> distinct;
        rep(i,0,n) distinct.insert(a[i]);
        int numdistinct = sz(distinct);
        map<int,int> lo, hi;
        rep(i,0,n) {
            if(!lo.count(a[i])) lo[a[i]] = i;
            hi[a[i]] = i;
        }
        int last = -1, count=0;
        int best=0;
        for(int x:distinct) {
            if(last>lo[x]) count = 1;
            else ++count;
            last = hi[x];
            best=max(best,count);
        }
        cout<<numdistinct-best<<"\n";
    }
}
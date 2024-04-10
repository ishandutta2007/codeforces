#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,char>> ch;
    rep(i,0,n) {
        int l;
        cin>>l;
        int lo;
        cin>>lo;
        int hi = lo;
        bool bad = false;
        rep(i,1,l) {
            int x;
            cin>>x;
            if(x>lo) bad = true;
            else lo = x;
        }
        if(!bad) {
            ch.emplace_back(hi,'A');
            ch.emplace_back(lo,'B');
        }
    }
    sort(all(ch));
    ll tot = 0, x = 0;
    for(auto &p:ch) {
        if(p.second=='A') {
            ++x;
        }
        else {
            tot += x;
        }
    }
    tot = ((ll)n)*n-tot;
    cout<<tot<<endl;
}
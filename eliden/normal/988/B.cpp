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
    int n;
    vector<pair<int,string>> ss;
    cin >> n;
    rep(i,0,n) {
        string s;
        cin >> s;
        ss.emplace_back(sz(s),s);
    }
    sort(all(ss));
    bool ok=true;
    rep(i,0,n-1) {
        bool substr=false;
        const string &s1=ss[i].second, &s2=ss[i+1].second;
        int m1 = sz(s1), m2=sz(s2);
        rep(j,0,m2-m1+1) {
            bool works=true;
            rep(k,j,j+m1) if(s1[k-j]!=s2[k]) works=false;
            if(works) substr=true;
        }
        if(!substr) ok=false;
    }
    if(ok) {
        cout<<"YES\n";
        rep(i,0,n) cout<<ss[i].second<<"\n";
    }
    else cout<<"NO\n";
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
using ll = long long;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int MAXA=102;
    vi count(MAXA,-1);
    int n, k;
    cin >> n >> k;
    rep(i,0,n) {
        int a;
        cin >> a;
        count[a]=i;
    }
    vi team;
    rep(i,0,MAXA) if(count[i]!=-1) {
        team.push_back(count[i]+1);
        if(sz(team)==k) break;
    }
    if(sz(team)<k) cout<<"NO\n";
    else {
        cout << "YES\n";
        for(int x:team) cout<<x<<" ";
        cout << "\n";
    }
}
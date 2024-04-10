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
    int n, m=3;
    cin >> n;
    vector<vi> val(n,vi(m));
    rep(i,0,n) rep(j,0,m) cin >> val[i][j];
    vi left(n);
    rep(i,0,n) left[i]=i;
    auto cmp = [&](int a, int b) { return val[a]<val[b]; };
    sort(all(left), cmp);
    vector<pii> ans;
    for(int j=m-1; j>=0; --j) {
        vi nextleft;
        rep(i,0,sz(left)) {
            if(i==sz(left)-1) {
                nextleft.push_back(left[i]);
                continue;
            }
            bool match = true;
            rep(k,0,j) if(val[left[i]][k]!=val[left[i+1]][k]) match = false;
            if(match) {
                ans.emplace_back(left[i],left[i+1]);
                ++i;
            }
            else nextleft.push_back(left[i]);
        }
        left = nextleft;
    }
    for(auto p:ans) {
        cout<<p.first+1<<" "<<p.second+1<<"\n";
    }
}
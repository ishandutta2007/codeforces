#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v[2];
    rep(i,0,n) {
        int a, b;
        cin >> a >> b;
        if (a < b)
            v[0].emplace_back(make_pair(a, b), i);
        else
            v[1].emplace_back(make_pair(-a, -b), i);
    }
    auto u = v[0];
    if (sz(v[1]) > sz(v[0]))
        u = v[1];
    sort(all(u));
    cout << sz(u) << endl;
    rrep(i,sz(u),0) {
        cout << u[i].second+1 << " ";
    }
    cout << endl;
}
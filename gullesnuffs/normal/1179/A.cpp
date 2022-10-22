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
    int n, q;
    cin >> n >> q;
    deque<int> d;
    rep(i,0,n) {
        int a;
        cin >> a;
        d.push_back(a);
    }
    vector<pair<int, int>> ans;
    rep(i,0,3*n+5) {
        int a = d.front();
        d.pop_front();
        int b = d.front();
        d.pop_front();
        d.push_front(max(a, b));
        d.push_back(min(a, b));
        ans.push_back(make_pair(a, b));
    }
    rep(i,0,q) {
        ll m;
        cin >> m;
        --m;
        if (m >= sz(ans)) {
            m = (m%(n-1))+2*(n-1);
        }
        cout << ans[m].first << " " << ans[m].second << endl;
    }
}
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
    vector<int> a(n);
    ll tot = 0;
    ll coal = 0;
    vector<int> ans;
    rep(i,0,n) {
        cin >> a[i];
        tot += a[i];
        if (i) {
            if (a[0] >= 2*a[i]) {
                coal += a[i];
                ans.push_back(i);
            }
        } else {
            coal += a[i];
            ans.push_back(0);
        }
    }
    if (coal*2 > tot) {
        cout << sz(ans) << endl;
        for (auto it : ans)
            cout << it+1 << " ";
    }
    else {
        cout << 0 << endl;
    }
}
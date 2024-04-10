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
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    set<int> seen;
    set<pair<int, int>> ok;
    rep(i,1,n+1) {
        if (i > 1)
            ok.insert(make_pair(i, i-1));
        if (i < n)
            ok.insert(make_pair(i, i+1));
        ok.insert(make_pair(i, i));
    }
    rep(i,0,k) {
        cin >> x[i];
        ok.erase(make_pair(x[i], x[i]));
        if (seen.count(x[i]-1))
            ok.erase(make_pair(x[i]-1, x[i]));
        if (seen.count(x[i]+1))
            ok.erase(make_pair(x[i]+1, x[i]));
        seen.insert(x[i]);
    }
    cout << sz(ok) << endl;
}
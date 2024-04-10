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
    vector<int> f(n);
    rep(i,0,n) {
        cin >> f[i];
        --f[i];
    }
    rep(i,0,n) {
        int j = f[i];
        int k = f[j];
        if (f[k] == i) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
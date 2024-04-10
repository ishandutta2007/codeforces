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
    int T;
    cin >> T;
    while (T--) {
        int ang;
        cin >> ang;
        bool ok = 0;
        rep(n,3,100000) {
            if ((ang*n)%180 == 0 && (ang*n)/180 <= n-2) {
                cout << n << endl;
                ok = 1;
                break;
            }
        }
        if (!ok)
            cout << "-1" << endl;
    }
}
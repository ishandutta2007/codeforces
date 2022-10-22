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

bool A[5201][5201];

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    rep(i,0,n) {
        string s;
        cin >> s;
        rep(j,0,n/4) {
            int k = (s[j] <= '9' && s[j] >= '0') ? (s[j] - '0') : (s[j] - 'A' + 10);
            if (k&8)
                A[i][4*j] = 1;
            if (k&4)
                A[i][4*j+1] = 1;
            if (k&2)
                A[i][4*j+2] = 1;
            if (k&1)
                A[i][4*j+3] = 1;
        }
    }
    int ans = 1;
    vector<int> failed;
    rep(i,2,n+1) {
        if (n%i)
            continue;
        bool ok = 1;
        for (int f : failed) {
            if (i%f == 0) {
                ok = 0;
                break;
            }
        }
        if (!ok)
            continue;
        if (i%ans)
            continue;
        rep(j,0,n) {
            int J = (j/i)*i;
            rep(K,0,n/i) {
                rep(k,K*i,(K+1)*i) {
                    if (A[J][K*i] != A[j][k]) {
                        ok = false;
                    }
                }
            }
            if (!ok)
                break;
        }
        if (!ok)
            continue;
        ans = i;
    }
    cout << ans << endl;
}
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
    
int n, m;

int dis(int x, int y) {
    int ret = y - x;
    if (ret < 0)
        ret += n;
    return ret;
}

int main(){
	ios::sync_with_stdio(0);
    cin >> n >> m;
    vector<vector<int>> b(n);
    rep(i,0,m) {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        b[A].push_back(dis(A, B));
    }
    rep(i,0,n)
        sort(all(b[i]));
    rep(i,0,n) {
        int ans = 0;
        rep(j,0,n) {
            if (b[j].size() == 0)
                continue;
            int newAns = dis(i, j) + (sz(b[j])-1) * n + b[j][0];
            ans = max(ans, newAns);
        }
        cout << ans << " ";
    }
    cout << endl;
}
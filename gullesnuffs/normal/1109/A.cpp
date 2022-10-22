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

int cnt[2][1<<21];

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int x=0;
    cnt[1][0]=1;
    ll ans = 0;
    rep(i,0,n) {
        cin >> a[i];
        x ^= a[i];
        ans += cnt[i%2][x];
        cnt[i%2][x]++;
    }
    cout << ans << endl;
}
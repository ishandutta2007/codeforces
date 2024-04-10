#include <bits/stdc++.h>
#define MOD 998244353 
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
    ll n;
    string s;
    cin >> n >> s;
    ll numBegin, numEnd;
    for(numBegin=0; numBegin < n && s[numBegin] == s[0]; ++numBegin);
    for(numEnd=0; numEnd < n && s[n-1-numEnd] == s[n-1]; ++numEnd);
    ll ans;
    if (numBegin == n) {
        ans = ((n+1)*n)/2;
    }
    else if (s[0] == s.back()) {
        ans = (numBegin + 1) * (numEnd + 1);
    }
    else {
        ans = numBegin + numEnd + 1;
    }
    ans %= MOD;
    cout << ans << endl;
}
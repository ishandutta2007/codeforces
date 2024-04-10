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
    ll N, K;
    cin >> N >> K;
    ll best = N+1;
    ll bestA = -1;
    ll bestInd = -1;
    rep(i,0,K) {
        ll a;
        cin >> a;
        ll b = N/a;
        ll r = N-b*a;
        if (r < best) {
            best  =r;
            bestA = a;
            bestInd = i+1;
        }
    }
    cout << bestInd << " " << (N/bestA) << endl;
}
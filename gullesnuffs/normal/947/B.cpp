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
    int N;
    cin >> N;
    vector<ll> V(N);
    vector<ll> T(N);
    rep(i,0,N)
        cin >> V[i];
    rep(i,0,N)
        cin >> T[i];
    priority_queue<ll> pq;
    ll sumT = 0;
    ll ans = 0;
    rep(i,0,N) {
        pq.push(-(V[i] + sumT));
        ans += V[i];
        ll melted = T[i] * pq.size();
        ans -= T[i] * pq.size();
        sumT += T[i];
        while (pq.size() > 0 && pq.top()+sumT >= 0) {
            ans += pq.top()+sumT;
            melted -= pq.top()+sumT;
            pq.pop();
        }
        cout << melted << " ";
    }
}
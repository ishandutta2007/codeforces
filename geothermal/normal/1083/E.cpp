#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef complex<ll> cl;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<cl> vcl;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
ld cross(pl l1, pl l2){
    return ((ld)(l1.f-l2.f))/((ld)(l2.s-l1.s));
}
deque<pl> eq;
void add(pl x){
    while(eq.size() >= 2){
        pl a1 = eq[0];
        pl a2 = eq[1];
        if(cross(x, a1) >= cross(x, a2))
            eq.pop_front();
        else
            break;
    }
    eq.push_front(x);
}
ll func(pl a, ll x){
    return a.f+a.s*x;
}
ll find(ll x){
    ll l = 0;
    ll r = eq.size()-1;
    while(l < r){
        ll m = (l+r)/2;
        if(func(eq[m+1], x) > func(eq[m], x))
            l = m+1;
        else
            r = m;
    }
    return func(eq[l], x);
} 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;

    vector<vl> data(N);
    F0R(i, N) {
        ll X, Y, A; cin >> X >> Y >> A; data[i] = {X, Y, A};
    }
    sort(all(data));
    add({0, 0});
    ll best = 0;
    F0R(i, N) {
        ll cur = find(data[i][1])*1 + data[i][0] * data[i][1] - data[i][2];
        /*cout << cur << endl;
        cout << sz(hull) << " " << sz(vecs) << endl;
        F0R(i, sz(hull)) {
            cout << hull[i] << " ";
        }
        cout << endl;
        F0R(i, sz(vecs)) {
            cout << vecs[i] << " ";
        }
        cout << endl;*/
        best = max(best, cur);
        add({cur, -1*data[i][0]});
    }

    cout << best << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
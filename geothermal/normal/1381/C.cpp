#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

class Comp
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second != b.second) {
            return a.s < b.s;
        } else return a.f < b.f;
    }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N, X, Y; cin >> N >> X >> Y;
        int A[N]; F0R(i, N) cin >> A[i];
        F0R(i, N) A[i]--;

        bool used[N+1];  F0R(i, N+1) used[i] = false;
        F0R(i, N) used[A[i]] = true;
        int un = 0;
        F0R(i, N+1) {
            if (!used[i]) un = i;
        }

        vector<vi> cols(N+1);
        F0R(i, N) cols[A[i]].pb(i);
        priority_queue<pi, vpi, Comp> q;
        F0R(i, N+1) {
            q.push({i, sz(cols[i])});
        }
        int ans[N];
        F0R(i, X) {
            pi cur = q.top(); q.pop();
            cur.s--; q.push(cur);
            int pos = cols[cur.f][cur.s];
            cols[cur.f].pop_back();
            ans[pos] = cur.f;
//            cout << cur.f << " " << cur.s << endl;
        }


        Y -= X;
        stack<pi> av;
        stack<pi> need;
        vector<pi> colors;
        F0R(i, N+1) {
            colors.pb({sz(cols[i]), i});
        }
        sort(all(colors)); 
        pi colN = colors[N];
        swap(colN.f, colN.s);
        need.push(colN);
        F0R(i, N) {
            pi X = colors[i];
            swap(X.f, X.s);
            av.push(X);
            need.push(X);
        }
        av.push(colN);
        while (!need.empty()) {
            pi cur = need.top(); need.pop();
            if (cur.s == 0) {
                continue;
            }
            cur.s--; need.push(cur);
            while (!av.empty() && av.top().s == 0) {
                av.pop();
            }
            pi use = {-1, -1};
            if (!av.empty()) {
                use = av.top(); av.pop();
            }
            if (use.f == cur.f) {
                while (!av.empty() && av.top().s == 0) {
                    av.pop();
                }
                pi newUse = {-1, -1};
                if (!av.empty()) {
                    newUse = av.top(); av.pop();
                }
                if (newUse.s > 0) {
                    newUse.s--;
                    av.push(newUse);
                }
                if (use.s > 0) {
                    use.s--;
                    av.push(use);
                }
                use = newUse;
            } else if (use.s > 0) {
                use.s--;
                av.push(use);
            }
//            cout << cur.f << " " << cur.s << " " << use.f << " " << use.s << endl;
            if (use.s >= 0 && Y > 0) {
                int pos = cols[cur.f][cur.s];
                cols[cur.f].pop_back();
                ans[pos] = use.f;
                Y--;
            } else {
                av.push(use);
                int pos = cols[cur.f][cur.s];
                cols[cur.f].pop_back();
                ans[pos] = un;

            }
//            cout << "TEST" << " " << cur.f << " " << cur.s << " " << use.f << " " << use.s << " " << Y << nl;
        }
/*        while (q.top().s > 0) {
            pi cur = q.top(); q.pop();
            cur.s--; q.push(cur);
            int pos = cols[cur.f][cur.s];
            cols[cur.f].pop_back();
            ans[pos] = un;
//            cout << cur.f << " " << cur.s << endl;
        }*/

        if (Y != 0) {
            cout << "NO" << nl; goto done;
        }
        cout << "YES" << nl;
        F0R(i, N) {
            cout << ans[i]+1 << " ";
        }
        cout << nl;
        done:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
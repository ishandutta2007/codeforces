#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 501; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    string S1, S2; cin >> S1 >> S2;
    int N = sz(S1), M = sz(S2);
    int prev[N+1][M+1][MX];
    F0R(i, N+1) F0R(j, M+1) F0R(k, MX) prev[i][j][k] = -1; 
    queue<int> q;
    q.push(0);
    prev[0][0][0] = 0;
    while (!q.empty()) {
        int curVal = q.front(); q.pop();
        pair<pi, int> curData = {{curVal / (M+1) / MX, (curVal / MX) % (M+1)}, (curVal % MX)};
        int A = curData.f.f;
        int B = curData.f.s;
        int C = curData.s;
        //case 1: (
        int nA = A, nB = B, nC = C+1;
        if (A < N && S1[A] == '(') nA++;
        if (B < M && S2[B] == '(') nB++;
        if (nC < MX && prev[nA][nB][nC] == -1) { 
            q.push(nC+MX*(nB+(M+1)*nA));
            prev[nA][nB][nC] = curVal;
            
        }

        nA = A; nB = B; nC = C-1;
        if (nC < 0) continue;
        if (A < N && S1[A] == ')') nA++;
        if (B < M && S2[B] == ')') nB++;
        if (prev[nA][nB][nC] == -1) {
            q.push(nC+MX*(nB+(M+1)*nA));
            prev[nA][nB][nC] = curVal;
        }
    }


    vector<char> ans;
    int A = N, B = M, C = 0;
    while (A != 0 || B != 0 || C != 0) {
//        cout << A << " " << B << " " << C << endl;
        if (C >= MX || prev[A][B][C] == -1) { 
            cout << -1 << endl; return 0;
        }
        int curVal = prev[A][B][C]; 
        pair<pi, int> prevData = {{curVal / (M+1) / MX, (curVal / MX) % (M+1)}, (curVal % MX)};
        
        A = prevData.f.f;
        B = prevData.f.s;
        bool X = prevData.s < C;
        C = prevData.s;
        if (X) {
            
            ans.pb('(');
        } else {
            ans.pb(')');
        }
    }

    reverse(all(ans));
    F0R(i, sz(ans)) cout << ans[i];
    cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
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
const int MX = 100001; //check the limits, dummy
const double EPS = 1e-5;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int mid = (N+2)/2;
    vi starts(3), lens(3);
    starts[0] = 0;
    starts[1] = 1;
    starts[2] = 0;
    lens[0] = mid-1;
    lens[1] = mid-2;
    lens[2] = N;
    if (N == 2) {
        lens[0] = 1;
        lens[1] = 1;
        lens[2] = -1;
    } else if (N == 1) {
        starts[0] = 0;
        lens[0] = 1;
        lens[1] = -1;
        lens[2] = -1;
    } else if (N == 3) {
        starts[0] = 0;
        starts[1] = 1;
        starts[2] = 2;
        lens[0] = 1;
        lens[1] = 1;
        lens[2] = 1;
    }



    

    vector<vector<double>> A[26];

    F0R(iter, 3) {
        int len = lens[iter];
        if (len <= 0) continue;
        int start = starts[iter];
        int end = start+len-1;
        cout << "? " << start+1 << " " << end+1 << endl;

        int cnt = len * (len+1) / 2;
        int countIn[len][26]; F0R(i, len) F0R(j, 26) countIn[i][j] = 0;
        F0R(i, cnt) {
            string S; cin >> S;
            F0R(j, sz(S)) {
                countIn[sz(S) - 1][S[j] - 'a']++;
            }
        }


        vpi pairs;
        int countRem[26]; F0R(i, 26) countRem[i] = countIn[len-1][i];
        FORd(i, len/2, len-1) {
            vi vals;
            int countCur[26];
            F0R(j, 26) {
//                countIn[i][j] -= countIn[i+1][j];
                countCur[j] = countIn[i][j] - countIn[i+1][j];
            }
            F0R(j, 26) {
                F0R(k, countRem[j] - countCur[j]) vals.pb(j);
            }
            F0R(j, 26) {
                countRem[j] = countCur[j];
            }


            /*F0R(j, 26) {
                countIn[i][j] -= countIn[len-1][j] * (len-i+1);

            }
            F0R(j, 26) {
                while(countIn[i][j] <= -1) {

                    vals.pb(j);
                    countIn[i][j]++;
                }
            }*/
//            cout << sz(vals) << endl;
            if (sz(vals) > 1) pairs.pb({vals[0], vals[1]});
            if (sz(vals) == 1) pairs.pb({vals[0], -1});
        }
        F0R(i, sz(pairs)) {
            countIn[len-1][pairs[i].f]--;
            if (pairs[i].s != -1) countIn[len-1][pairs[i].s]--;
        }

        vi vals;
        F0R(i, 26) {
            while (countIn[len-1][i] >= 1) {
            vals.pb(i);
            countIn[len-1][i]--;
            }
        }
        if (sz(vals) > 1) pairs.pb({vals[0], vals[1]});
        if (sz(vals) == 1) pairs.pb({vals[0], -1});

        F0R(i, sz(pairs)) {
//            cout << pairs[i].f << " " << pairs[i].s << endl;
            //start+i, end-i = pairs
            vector<double> curEq[26];
            F0R(j, 26) {
                F0R(k, N+1) {
                    curEq[j].pb(0);
                }
                curEq[j][start+i] = 1;
                curEq[j][end-i] = 1;
                
            }
            curEq[pairs[i].f][N] += 1;
            if (pairs[i].s != -1) curEq[pairs[i].s][N] += 1;
            F0R(j, 26) {
                A[j].pb(curEq[j]);
            }
        }
    }

    vector<double> ans[26];
    F0R(i, 26) {
        
        int val = gauss(A[i], (ans[i]));
/*        if (i == 0) {
            F0R(j, 7) {
                F0R(k, N+1) {
//                    cout << A[0][j][k] << " ";
                }
//                cout << endl;
            }
        }*/
        assert(val == 1);
    }

    string S; F0R(i, N) S += ' ';
//////////////////    cout << sz(A[0]) << endl;
    F0R(i, 26) {
        F0R(j, N) {
            if (abs((ans)[i][j] - 1) < 1e-4) {
                S[j] = 'a'+i;
            }
        }
    }
    cout << "! " << S << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343
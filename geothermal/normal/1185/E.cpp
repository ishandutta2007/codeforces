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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    F0R(testCase, T) {
        int N, M; cin >> N >> M;
        char data[N][M]; F0R(i, N) F0R(j, M) cin >> data[i][j];
        int countN[N][26], countM[M][26];
        F0R(i, 26) {
            F0R(j, N) countN[j][i] = 0;
            F0R(j, M) countM[j][i] = 0;
        }
        F0R(i, N) {
            F0R(j, M) {
                if (data[i][j] != '.') {
                    countN[i][data[i][j] - 'a']++;
                    countM[j][data[i][j] - 'a']++;
                }
            }
        }
        bool started = false;
        vector<vi> ans;
        vpi blanks;
        F0Rd(curLetter, 26) {
            char cur = 'a'+curLetter;
            bool found = false;
            F0R(i, N) {
                F0R(j, M) {
                    if (data[i][j] == cur) {
                        started = true;
                        if (found) {
                            cout << "NO" << endl; goto nextCase;
                        }
                        found = true;
                        if (countM[j][curLetter] > 1) {
                            int end = i;
                            FOR(k, i, N) {
                                if (data[k][j] != cur && data[k][j] != '!') {
                                    end = k-1; break;
                                }
                                data[k][j] = '!';
                                if (k == N-1) end = k;
                            }

                            vi curAns; curAns.pb(i); curAns.pb(j); curAns.pb(end); curAns.pb(j);
                            ans.pb(curAns);

                        } else if (countN[i][curLetter] > 1) {

                            int end = j;
                            FOR(k, j, M) {
                                if (data[i][k] != cur && data[i][k] != '!') {
                                    end = k-1; break;
                                }
                                data[i][k] = '!';
                                if (k == M-1) end = k;
                            }
                            vi curAns;
                            curAns.pb(i); curAns.pb(j); curAns.pb(i); curAns.pb(end);
                            ans.pb(curAns);

                        } else {
                            data[i][j] = '!';
                            vi curAns; curAns.pb(i); curAns.pb(j); curAns.pb(i); curAns.pb(j);
                            ans.pb(curAns);
                        }
                    }
                }
            }

            if (started && !found) {
                F0R(i, N) {
                    F0R(j, M) {
                        if (data[i][j] == '!') {
                            found = true;
                            vi curAns; curAns.pb(i); curAns.pb(j); curAns.pb(i); curAns.pb(j); ans.pb(curAns);
                            goto done;
                        }
                    }
                }
                done:;
                if (!found) {
                    cout << "NO" << endl; goto nextCase;
                }
            }
        }

        cout << "YES" << endl;
        reverse(all(ans));
        cout << sz(ans) << endl;
        F0R(i, sz(ans)) {
            F0R(j, 4) {
                cout << ans[i][j]+1 << " ";
            }
            cout << endl;
        }


        nextCase:;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
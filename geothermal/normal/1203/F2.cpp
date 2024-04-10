//I would like it to be known that I would have solved this in-contest
//except I had to leave after an hour.
//it be like that sometimes

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
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    
    int N; cin >> N;
    int R; cin >> R;
    int M = N;
    
	multiset<pi> posJobs;
	vector<pair<int, pi> > negData;
	F0R(i, N) {
		int A, B; cin >> A >> B;
		if (B >= 0) {
			posJobs.insert(mp(A, B));
		} else {
			
			negData.pb({max(A, -1*B) + B, {max(A, -1*B), B}});
		}
	}
	

	int ans = 0;
	auto it = posJobs.begin();
	
	for (it = posJobs.begin(); it != posJobs.end(); it++) {
		if (it->f <= R) {
			ans++; R += it->s;
		}
	}
	
	sort(all(negData));
	reverse(all(negData));
	N = sz(negData);

	int dp[61000];
	
	F0R(i, 61000) {
		dp[i] = 0;
	}
	
	F0R(j, N) {
		F0R(i, R+1) {
			if (i >= negData[j].s.f && i + negData[j].s.s >= 0) {
				dp[i + negData[j].s.s] = max(dp[i + negData[j].s.s], dp[i]+1);
			}
		}
	}
	
	F0Rd(i, R+1) {
		dp[i] = max(dp[i], dp[i+1]);
	}
	
	/*F0Rd(i, 15) {
		cout << i << " " << dp[i] << endl;
	}*/
	
	/*if (ans + dp[0] == M) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}*/
	
	//cout << ans << endl;
	
	cout << ans + dp[0] << endl;
	
	
	//darn, I def could have solved this in contest if I didn't have to leave after an hour
	// :'(
	
	//oh well, my penalty was pretty bad anyway
	//I clearly was not in a thinking mood this morning riprip
	//win some, lose some I guess
	
	//nice problem though
	
	/*
	 * Figured I'd prove the solution since I'm on a plane ride
	 * and I'm extremely bored.
	 * 
	 * Let A = max(a, b) and B = -b where a and b are a_i and b_i from the problem.
	 * The key lemma is that given any set of negative jobs that can be completed in any order
	 * they can be completed in decreasing order of A-B.
	 * 
	 * We do this by showing that if we have two jobs with (A, B) = (A1, B1) for job 1 and (A2, B2) for job 2
	 * then if A2-B2 >= A1-B1 and starting with rating R, we can complete job 1, then job 2,
	 * we can complete job 2, then job 1.
	 * 
	 * If we can complete job 1, then job 2, we must have R - B1 >= A2
	 * So R >= B1 + A2.
	 * 
	 * Our assumed inequality simplifies to A2 + B1 >= A1 + B2.
	 * 
	 * So substituting gives R >= A1 + B2, so R - B2 >= A1.
	 * 
	 * After completing job 2 we have R - B2 rating, and this is at least A1
	 * which implies that we can complete job 1.
	 * 
	 * Then, suppose we can complete some set of jobs in some arbitrary order.
	 * We have proven that we can swap two adjacent elements that are out of order (by A-B).
	 * This is the only operation we need to perform bubble sort, so we
	 * can sort these in decreasing order of A-B and still have a working order.
	 * 
	 * Therefore, if we can complete some set of jobs in any order,
	 * we can complete them in decreasing order of A-B.
	 * 
	 * If someone is reading this, here's a tip: when you want to prove
	 * that some items can be sorted in some order while maintaining
	 * some invariant, prove that two adjacent elements can be swapped
	 * instead.  Usually that's a lot easier/more direct.
	 * 
	 * Back to the original problem!  Obviously, we should start by processing
	 * all doable nonnegative jobs.  Then, the negative jobs become a thing.
	 * 
	 * With max rating = about 60,000, we can safely do an O(NR) DP
	 * for the negative jobs.  Sort the jobs in the above order
	 * and let dp[i][j] be the best we can do at at least i rating
	 * with some subset of the first j jobs.
	 * 
	 * Transitions are pretty easy in O(1) and the answer is dp[0][N]
	 * after switching N to the count of negative jobs.
	 * 
	 * YEET
	 * 
	 * btw this trivializes F1, of course
	 * can't say I'm entirely sure what makes F1 easier, perhaps
	 * some more motivated sorting works but only when you can
	 * complete every job?
	 */
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
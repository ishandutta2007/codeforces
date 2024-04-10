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

int A[35005];
ll dp[35005];
ll res[35005];
int n, k;

struct DP {
	int lo(int ind) { return ind; }
	int hi(int ind) { return n+1; }
	int M[35005];
	int Mcnt;
	int a, b;

	inline void add(int x){
		if(!(M[A[x]]++)){
			++Mcnt;
		}
	}

	inline void subtract(int x){
		if(!(--M[A[x]])){
			--Mcnt;
		}
	}

	ll f(int ind, int k) { 
		while(ind > a){
			subtract(a);
			++a;
		}
		while(ind < a){
			--a;
			add(a);
		}
		while(k > b){
			add(b);
			++b;
		}
		while(k < b){
			--b;
			subtract(b);
		}
		return Mcnt+dp[k]; 
	}
	void store(int ind, int k, ll v) { res[ind] = v; }

	void rec(int L, int R, int LO, int HI) {
		if (L >= R) return;
		int mid = (L + R) >> 1;
		pair<ll, int> best(-LLONG_MAX, LO);
		rep(k, max(LO,lo(mid)), min(HI,hi(mid)))
			best = max(best, make_pair(f(mid, k), k));
		store(mid, best.second, best.first);
		rec(L, mid, LO, best.second+1);
		rec(mid+1, R, best.second, HI);
	}
	void solve(int L, int R) { 
		Mcnt=0;
		a=0; b=0; rec(L, R, INT_MIN, INT_MAX); }
} dps[55];

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> k;
	rep(i,0,n)
		cin >> A[i];
	rep(j,0,k)
	{
		dps[j].solve(0, n);
		rep(i,0,n){
			dp[i]=res[i];
		}
	}
	cout << res[0] << endl;
}
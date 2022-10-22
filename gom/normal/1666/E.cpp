#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
#define sortv(v) sort(all(v))
#define uniqv(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define FI first
#define SE second
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define test 1
#define TEST if(test)
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const int MOD = 1000000007; // 998244353
const int INF = 2e9;
const ll INFLL = 1e18;
const int MAX_N = 1000;

int L, N;

vector<int> v;
vector<pii> rv1, rv2;
int Mn;
vector<pii> ans;

bool chk1(int x){
	rv1.clear();
	int n = 0;
	for(int i=0; i<N; i++){
		n = max(n, v[i]-x);
		if(n+x>v[i+1]){
			return false;
		}
		rv1.pb({n, n+x});
		n = n+x;
	}
	rv1.pb({L, L});
	return true;
}

bool chk2(int x){
	rv2.clear();
	rv2.pb({0, 0});
	int mn = 0, mx=0;
	for(int i=0; i<N; i++){
		int n = v[i];
		int nxt = v[i+1];
		int nmn = max(mn + Mn, n);
		if(nmn-mx>x)	return false;
		int nmx = min(mx + x, nxt);
		if(nmx-mn<Mn)	return false;
		if(nmx<nmn)	return false;
		rv2.pb({nmn, nmx});
		mn = nmn;
		mx = nmx;
	}
	if(mx!=L)	return false;
	return true;
}

int main(){
	scanf("%d%d", &L, &N);
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x);
		v.pb(x);
	}
	v.pb(L);
	int s = 1, e = L, m;
	while(s<e){
		m = (s+e)/2+1;
		if(chk1(m)){
			s = m;
		}else{
			e = m-1;
		}
	}
	chk1(s);
	Mn = s;
	s = Mn; e = L;
	while(s<e){
		m = (s+e)/2;
		if(chk2(m)){
			e = m;
		}else{
			s = m+1;
		}
	}
	chk2(s);
	int Mx = s;
	int n = L;
	for(int i=N-1; i>=0; i--){
		int pmn = rv2[i].first, pmx = rv2[i].second;
		int mn = rv2[i+1].first, mx = rv2[i+1].second;
		int prv;
		if(n-Mn>pmx){
			prv = pmx;
		}else{
			prv = n - Mn;
		}
		ans.pb({prv, n});
		n = prv;
	}
	n=0;
	int nxt=0;
	for(int i=N-1; i>=0; i--){
		nxt = min(n+Mx, ans[i].second);
		printf("%d %d\n", n, nxt);
		n = nxt;
	}

	return 0;
}
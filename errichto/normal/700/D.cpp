#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;
const int magic = 500;
const int hack = 1000;

int in[nax];
int low[nax], high[nax];

vi queries[nax / magic + 5];

int occur[nax];
int how[nax];
ll ans_memo[nax];

void foo(int & tmp, set<int> & s, int dif) {
	if(--how[tmp] == 0 && tmp > hack) s.erase(tmp);
	tmp += dif;
	if(++how[tmp] == 1 && tmp > hack) s.insert(tmp);
}

int main() {
	int n;
	scanf("%d", &n);
	RI(i, n) scanf("%d", &in[i]);
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; ++i) {
		scanf("%d%d", &low[i], &high[i]);
		queries[low[i] / magic].push_back(i);
	}
	
	
	for(int where = 0; where < nax / magic; ++where) if(!queries[where].empty()) {
		sort(queries[where].begin(), queries[where].end(), [&] (int a, int b) {
			return high[a] < high[b];
		});
		for(int i = 0; i < nax; ++i) how[i] = 0;
		for(int i = 0; i < nax; ++i) occur[i] = 0;
		set<int> s;
		int cur_low = 0, cur_high = 0;
		for(int iq : queries[where]) {
			while(cur_high < high[iq]) {
				++cur_high;
				foo(occur[in[cur_high]], s, 1);
			}
			while(cur_low < low[iq]) {
				foo(occur[in[cur_low]], s, -1);
				++cur_low;
			}
			while(cur_low > low[iq]) {
				--cur_low;
				foo(occur[in[cur_low]], s, 1);
			}
			vector<pii> A;
			RI(i, hack) if(how[i] > 0) A.push_back({i, how[i]});
			for(int i : s) if(i > 0) A.push_back({i, how[i]});
			
			//printf("iq = %d\n", iq);
			//for(pii a : A) printf("(%d, %d), ", a.first, a.second);
			//puts("");
			//puts("");
			
			vector<pii> B;
			int a = 0, b = 0;
			long long ans = 0;
			#define prev prev_compile
			int prev = 0;
			
			while(a < (int) A.size() || b < (int) B.size()) {
				pii here;
				if(a < (int) A.size() && b < (int) B.size() && A[a].first == B[b].first) {
					here = make_pair(A[a].first, A[a].second + B[b].second);
					++a;
					++b;
				}
				else if(b == (int) B.size() || (a < (int) A.size() && A[a].first < B[b].first)) {
					here = A[a++];
				}
				else here = B[b++];
				if(prev) {
					ans += prev + here.first;
					//printf("prev = %d\n", prev);
					B.push_back(make_pair(prev + here.first, 1));
					--here.second;
					prev = 0;
				}
				if(here.second >= 2) {
					ans += 2LL * here.first * (here.second / 2);
					B.push_back(make_pair(2 * here.first, here.second / 2));
					here.second %= 2;
				}
				if(here.second) prev = here.first;
			}
			//for(pii a : B) printf("(%d, %d), ", a.first, a.second);
			//puts("");
			
			
			ans_memo[iq] = ans;
			
			
			
		}
	}
	RI(i, q) printf("%lld\n", ans_memo[i]);
	/*while(q--) {
		int low, high;
		scanf("%d%d", &low, &high);
		pair<int,int> parka = mp(low, high);
		low += pot;
		high += pot;
		if(already.count(parka)) {
			printf("%lld\n", already[parka]);
			continue;
		}
		
		vector<pii> A = tr[low];
		if(low != high) A = merge(A, tr[high]);
		while(low < high - 1) {
			if(low % 2 == 0) A = merge(A, tr[low+1]);
			if(high % 2 == 1) A = merge(A, tr[high-1]);
			low /= 2;
			high /= 2;
		}
		
		
		
		already[parka] = ans;
		printf("%lld\n", ans);
	}*/
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_set>
#include<assert.h>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int n, low, high;
int t[nax], licz[nax], ones[nax], son[nax];
unordered_set<int> zle;
int odw(int i) { return n + 1 - i; }
ll res;

void rozwaz(int a) {
	zle.erase(a);
	if(licz[a] % 2 == 1 || licz[a] < 0) zle.insert(a);
}

bool jest_ok() {
	int dl = min(low - 1, n - high);
	if(son[dl] != dl) return false;
	if(high < n / 2) {
		int h2 = odw(high);
		// od high+1 do h2-1
		int a = high+1, b = h2-1;
		if(son[b] - son[a-1] != b-(a-1))
			return false;
	}
	if(odw(low) < n / 2) {
		int h1 = odw(low);
		// od h1+1 do low-1
		int a = h1+1, b = low-1;
		if(son[b] - son[a-1] != b-(a-1))
			return false;
	}
	
	int ss = (int) zle.size();
	if(ss >= 2) return false;
	if(n % 2 == 0) {
		return (ss == 0);
	}
	assert(n % 2 == 1);
	if(ss == 0) return true; // bywa gdy low i high w 1 polowie
	int a = *(zle.begin());
	return (licz[a] > 0);
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	scanf("%d", &n);
	if(n == 1) {
		puts("1");
		return 0;
	}
	RI(i, n) scanf("%d", &t[i]);
	RI(i, n) if(t[i] == t[odw(i)]) ones[i] = 1;
	RI(i, n+1) son[i] = son[i-1] + ones[i];
	low = 1;
	high = 1;
	licz[t[1]]++;
	licz[t[n]]--;
	RI(a, n) rozwaz(a);
	while(low <= n) {
		while(low > high || !jest_ok()) {
			++high;
			if(high > n) {
				printf("%lld\n", res);
				return 0;
			}
			if(n % 2 == 1 && n / 2 + 1 == high)
				licz[t[high]]++;
			else {
				licz[t[high]]++;
				if(low <= odw(high) && odw(high) <= high-1)
				{
					licz[t[high]] ++; // dodatkowo bo wczesniej na minusie
				}
				else licz[t[odw(high)]]--;
			}
			rozwaz(t[high]);
			rozwaz(t[odw(high)]);
			if(debug) puts("\ndupeczka");
			if(debug) RI(i, 6) printf("%d ", licz[i]);
			if(debug) puts("");
		}
		if(debug) assert(jest_ok());
		res += (ll) n + 1 - high;
		if(debug) printf("low = %d   high = %d\n", low, high);
		if(debug) RI(i, 6) printf("%d ", licz[i]);
		if(debug) puts("");
		
		if(n % 2 == 1 && n / 2 + 1 == low)
			licz[t[low]]--;
		else {
			licz[t[low]]--;
			if(low <= odw(low) && odw(low) <= high) licz[t[low]] --; // dodatkowo
			else licz[t[odw(low)]] ++;
		}
		rozwaz(t[low]);
		rozwaz(t[odw(low)]);
		++low;
		if(debug) puts("\nlapy w goreeee");
		if(debug) RI(i, 6) printf("%d ", licz[i]);
		if(debug) puts("");
	}
	printf("%lld\n", res);
	return 0;
}
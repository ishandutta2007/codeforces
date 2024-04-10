#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 4005;
const int SIZE = 1.2e7;

typedef long long H;

const int HT_SIZE = 1<<23, HT_AND = HT_SIZE - 1, HT_SIZE_ADD = HT_SIZE / 100;
H ht[HT_SIZE + HT_SIZE_ADD];
int data[HT_SIZE + HT_SIZE_ADD];

int get_pos(const H &hash){
	ll k = ((ll) hash) & HT_AND;
	while(ht[k] && ht[k] != hash)
		++k;
	return k;	
}

int get(const H &hash) {
	return data[get_pos(hash)];
}

void insert(const H &hash, int x){
	int k = get_pos(hash);
	if(!ht[k])
		ht[k] = hash, data[k] = x;
}

bool count(const H &hash){
	ll k = get_pos(hash);
	while(ht[k] && ht[k] != hash)
		++k;
	return ht[k] == hash;;
}


int a[N], sum[N];
int cnt;

inline ll get_index(int l, int r, int k, int turn) {
	return l * N * 1ll * N * N + r * N * 1ll * N + k * N + turn;
}

int calc(int l, int r, int k, int turn) {
	ll ind = get_index(l, r, k, turn);
	if (count(ind))
		return get(ind);
	if (turn == 0) {
		int res = 0;
		if (r - l < k) {
			insert(ind, 0);
			return 0;
		}
		res = calc(l + k, r, k, 1 - turn) + sum[l + k] - sum[l];
		if (r - l >= k + 1)
			res = max(res, calc(l + k + 1, r, k + 1, 1 - turn) + sum[l + k + 1] - sum[l]);
		insert(ind, res);
		return res;
	} else {
		int res = 0;
		if (r - l < k) {
			insert(ind, 0);
			return 0;
		}
		res = calc(l, r - k, k, 1 - turn) - sum[r] + sum[r - k];
		if (r - l >= k + 1)
			res = min(res, calc(l, r - k - 1, k + 1, 1 - turn) - sum[r] + sum[r - k - 1]);
		insert(ind, res);
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n)
		cin >> a[i], sum[i + 1] = sum[i] + a[i];
	cout << calc(0, n, 1, 0) << '\n';
	return 0;
}
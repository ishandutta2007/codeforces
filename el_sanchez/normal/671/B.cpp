#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 500500;
    
int n, k;
int h;
int a[MAXN];
ll sum[MAXN];

ll underSum(int h) {
	if (h <= a[0])
		return 0;
		
	int id = lower_bound(a, a + n, h + 1) - a;
	if (id == n) {
		id--;
		h = a[id];
	} else
		id--;
	
	//cout << "id = " << id << '\n';
	
	ll res = 1ll * h * (id + 1);
	res -= sum[id];
	
	return res;
}

ll upperSum(int h) {
	int id = lower_bound(a, a + n, h) - a;
	if (id == n) {
		return 0;
	}
	
	ll res = sum[n - 1] - (id > 0 ? sum[id - 1] : 0);
	res -= 1ll * (n - id) * h;
	
	return res;
}

bool good(int h) {
	//find h1

	int L = a[0], R = a[n - 1] + 1, mid;
	while (R - L > 1) {
		mid = (L + R) >> 1;
		
		if (underSum(mid) <= k)
			L = mid;
		else
			R = mid;
	}	
	
	int h1 = L;
	
	int h2 = h1 + h;
	
	//cout << h1 << ' ' << h2 << '\n';
	
	if (upperSum(h2) <= k)
		return 1;
	return 0;
}

int main() {
             
	cin >> n >> k;
	forn(i, n)
		scanf("%d", &a[i]);
	sort(a, a + n);

	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}
	
	if (k == 0) {
		cout << a[n - 1] - a[0] << '\n';
		return 0;
	}
	
	sum[0] = a[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i];

	int L = -1, R = INF, mid;
	while (R - L > 1) {
		mid = (L + R) >> 1;
		if (good(mid))
			R = mid;
		else
			L = mid;
	}
	
	//forn(i, 10)
	//	cout << underSum(i) << ' ' << upperSum(i) << '\n';

	if (R == 0) {
		if (sum[n - 1] % n != 0)
			R++;	
	}
	
	cout << R << '\n';
	
	return 0;
}
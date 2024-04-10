#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;
const int MAXK = 20;
    
int n, q;
int m[MAXN];
int a[MAXN], L, R;

int sparse[MAXN][MAXK];
int len[MAXN];

void sparse_build() {
	len[1] = 0;
	len[2] = 0;
	int curMax = 0;
	
	for (int i = 3; i < MAXN; i++) {
		if (i > (1 << (curMax + 1)))
			curMax++;
		len[i] = curMax;	
	}
	
	
	forn(i, n)
		sparse[i][0] = a[i];
	for (int j = 1; j < MAXK; j++)
		for (int i = 0; i < n; i++)
			if (i + (1 << (j - 1)) < n)
				sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);	
}

int get(int l, int r) { //[l, r]
	int curLen = len[r - l + 1];
	return max(sparse[l][curLen], sparse[r - (1 << curLen) + 1][curLen]);    
}

int B[MAXN][2];

int main() {

	cin >> n >> q;
	forn(i, n)
		scanf("%d", &m[i]);
	n--;
	forn(i, n) {
		a[i] = abs(m[i] - m[i + 1]);
	}
	
	sparse_build();
	/*
	forn(i, n)
		forab(j, i, n)
			cout << get(i, j) << '\n';
	*/		
	
	//cout << get(1, 3) << '\n';
	//int db = 0;
	forn(i, n) {
		//cerr << i << '\n';
		//left bound
		int L = -1;
		int R = i;
		int M;
		while (R - L > 1) {
			M = (L + R) >> 1;
			if (get(M, i) <= a[i])
				R = M;
			else
				L = M;
		}
		B[i][0] = R;
		
		//right bound
		L = i;
		R = n;
		while (R - L > 1) {
			M = (L + R) >> 1;
			if (get(i + 1, M) < a[i])
				L = M;
			else
				R = M;
		}
		B[i][1] = L;
		
		//db += (B[i][1] - i + 1) * (i - B[i][0] + 1);
	}
	/*
	cout << db << '\n';
	
	forn(i, n)
		cout << B[i][0] << ' ' << B[i][1] << '\n';
	*/	
	forn(qq, q) {
		scanf("%d%d", &L, &R);
		L--;
		R -= 2;
		
		if (L > R)
			printf("%d\n", 0);
		else {
			ll ans = 0;
			for (int i = L; i <= R; i++) {
				int curL = max(L, B[i][0]);
				int curR = min(R, B[i][1]);
				ans += 1ll * (i - curL + 1) * (curR - i + 1) * a[i];
			}
			
			printf("%I64d\n", ans);
		}
	}
	
	return 0;
}
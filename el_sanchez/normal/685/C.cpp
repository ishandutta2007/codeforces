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
const int MAXN = 100500;
const ll LINF = (ll)(3E18) + 100; //??

struct pt {
	ll x, y, z;

	pt(ll _x = 0, ll _y = 0, ll _z = 0) {
		x = _x, y = _y, z = _z;
	}
};

int T, n;
pt a[MAXN];
ll A[3];
ll bound[4][2];
ll B[4][2];

bool ok(ll d) {
	forn(i, 4) {
		bound[i][0] = -(ll)9E18;
		bound[i][1] = (ll)9E18;
	}
	
	forn(i, n) {
		bound[0][0] = max(bound[0][0], - a[i].x + a[i].y + a[i].z - d);
		bound[0][1] = min(bound[0][1], - a[i].x + a[i].y + a[i].z + d);
		bound[1][0] = max(bound[1][0], + a[i].x - a[i].y + a[i].z - d);
		bound[1][1] = min(bound[1][1], + a[i].x - a[i].y + a[i].z + d);
		bound[2][0] = max(bound[2][0], + a[i].x + a[i].y - a[i].z - d);
		bound[2][1] = min(bound[2][1], + a[i].x + a[i].y - a[i].z + d);
		bound[3][0] = max(bound[3][0], + a[i].x + a[i].y + a[i].z - d);
		bound[3][1] = min(bound[3][1], + a[i].x + a[i].y + a[i].z + d);
	}
	
	//cout << d << ":\n";
	
	bool success;
	forn(r, 2) {
		//cout << r << '\n';
		success = 1;
		
		forn(i, 3)
			forn(j, 2)
				B[i][j] = bound[i][j] - r;
		forn(j, 2)
			B[3][j] = bound[3][j] - 3 * r;		

		forn(i, 4) {
			if (abs(B[i][0]) & 1)
				B[i][0]++;
			if (abs(B[i][1]) & 1)
				B[i][1]--;
			forn(j, 2)
				B[i][j] /= 2;			
		}
		
		forn(i, 4)
			if (B[i][0] > B[i][1]) {
				success = 0;
				break;
			}
				
		forn(i, 3)
			A[i] = B[i][0];
		if (A[0] + A[1] > B[3][1] - A[2])
			success = 0;
		
		if (!success)
			continue;
		
		success = 1;
		/*
		forn(i, 4)
			cout << B[i][0] << ".." << B[i][1] << '\n';
		*/
			
		if (B[3][0] - A[0] > A[1] + A[2]) {
			success = 0;
			
			forn(i, 3) {
				ll add = min(B[i][1] - A[i], B[3][0] - A[0] - A[1] - A[2]);
				
				A[i] += add;
				if (B[3][0] - A[0] <= A[1] + A[2]) {
					success = 1;
					break;
				}
			}
		}
		
		if (!success)
			continue;
		
		forn(i, 3)
			A[i] = A[i] * 2 + r;
		success = 1;
		break;			
	}
		
	//cout << success << '\n';
	
	return success;
}

int main() {

	cin >> T;
	forn(_, T) {
		scanf("%d", &n);
		forn(i, n)
			scanf("%I64d%I64d%I64d", &a[i].x, &a[i].y, &a[i].z);	
			
		ll L = -1, R = LINF, mid;
		while (R - L > 1) {
			mid = (L + R) >> 1;
			if (ok(mid))
				R = mid;
			else
				L = mid;	
		}
		
		ok(R);
		printf("%I64d %I64d %I64d\n", (A[1] + A[2]) / 2, (A[0] + A[2]) / 2, (A[0] + A[1]) / 2);
	}          
		
    return 0;
}
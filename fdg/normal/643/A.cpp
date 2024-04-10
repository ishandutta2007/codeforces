#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(A) (int)A.size()
#define RFOR(i,a,b) for (int (i) = (a); (i) >= (b); --(i))
#define ll long long
#define sz(A) (int)A.size()

#define FREIN(FILE) freopen(FILE,"rt",stdin)
#define FREOUT(FILE) freopen(FILE,"wt",stdout)

typedef vector < int > vi;
typedef pair <int, int> pii;
const int MOD = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1000000000; //1e9
const int inf = 1e9+1;
const double eps = 1e-9;
int cnt[5005];
int a[5005];
int ans[5005];

int main() {
	//FREIN("input.txt");	
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	REP(i, n) {
		memset(cnt, 0, sizeof(cnt));
		int cur = -1;
		int val = -1;
		FOR(j, i, n) {
			cnt[a[j]]++;
			if (cnt[a[j]]>cur || (cur == cnt[a[j]] && val > a[j])) {
				cur = cnt[a[j]];
				val = a[j];
			}
			ans[val]++;
		}
	}
	REP(i, n) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
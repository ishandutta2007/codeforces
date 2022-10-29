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

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 200500;
const int MAXC = 459;
                                     
int n, v, w, k;              
int a[MAXN], sz, start[MAXN];
ll ans[MAXN], l[MAXN], r[MAXN], cur;

int main() {
                
	cin >> n;
	forn(i, n)
		scanf("%d", &a[i + 1]);
		
	for (int i = 1; i <= MAXC; i++) {
		for (int j = 2; j <= n; j++) {
			v = (j - 2) / i + 1;
			ans[i] += a[v] > a[j];	
		}
	}
	/*
	for (int i = 2; i <= MAXC + 1; i++)
		if (a[i] < a[1]) {
			l[i - 1]++;
			r[n - 1]++;	
		}
	*/			
	
	sz = 1;
	start[1] = MAXC + 1;
	start[0] = n;
	for (int i = 2; i <= n; i++) {
	    for (int j = 1; j <= sz; j++) {
	    	if (a[i] < a[j]) {
	    		l[start[j]]++;
	    		r[start[j - 1] - 1]++;
	    	}
	    }
		if (i == n)
			break;	
			
		v = i + 1;
		for (int j = 1; j <= sz; j++) {
			k = start[j];
			while (start[j] <= n - 1 && j != (v - 2) / start[j] + 1)
				start[j]++;	
		}
		
		if (start[sz] != MAXC + 1) {
			sz++;
			start[sz] = MAXC + 1;	
		}
		/*
		cout << "V = " << v << ":\n";
		for (int i = sz; i >= 1; i--)
			cout << start[i] << ' ';
		cout << '\n';
		*/
	}	
	cur = 0;
	for (int i = 1; i <= n - 1; i++) {
		cur += l[i];
		if (i > MAXC)
			ans[i] += cur;
		cur -= r[i];
	}
	
	for (int i = 1; i <= n - 1; i++)
		printf("%I64d ", ans[i]);
				
	return 0;
}
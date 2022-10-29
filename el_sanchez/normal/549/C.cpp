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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-11;
const int INF = 1E9;
const ll LINF = 1E18;     
const int MAXN = 111;

int n, k, steps, s[2], x;
int sum, a[2];

int main() {

	cin >> n >> k;
	steps = n - k;
	sum = 0;
	forn(i, n) {
		scanf("%d", &x);
		x &= 1;
		a[x]++;
		sum ^= x;
	}
	s[0] = (steps + 1) / 2;
	s[1] = steps - s[0];
	
	if (steps == 0) {
		if (sum & 1)
			cout << "Stannis";
		else
			cout << "Daenerys";
			
		return 0;
	}
	
	if (sum & 1) {
		if (steps & 1) {
			if (s[1] >= a[1] || ((s[1] >= a[0]) && !(a[0] & 1)))
				cout << "Daenerys";
			else
				cout << "Stannis";	 	
		} else {
			if (s[0] >= a[0] && !(a[0] & 1))
				cout << "Stannis";
			else
				cout << "Daenerys";
		}	
	} else {
		if (!(steps & 1)) {
			if (s[0] >= a[0] && (a[0] & 1))
				cout << "Stannis";
			else
				cout << "Daenerys";
		} else {
			if (s[1] >= a[1] || ((s[1] >= a[0]) && (a[0] & 1)))
				cout << "Daenerys";
			else
				cout << "Stannis";	 	
		}		
	}
	
	return 0;
}
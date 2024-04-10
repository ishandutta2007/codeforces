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
const ld eps = 1e-14;
const int INF = 1E9;		                    
const int MAXN = 100500 * 30;

int x[2], y[2];

int main() { 
        	
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	if (x[0] <= x[1] && y[0] <= y[1])
		cout << "Polycarp";
	else {
		int n[2];
		n[0] = n[1] = 0;
		n[1] = min(x[1], y[1]);
		x[1] -= n[1];
		y[1] -= n[1];
		n[1] += x[1] + y[1];
		n[0] = x[0] + y[0];
		if (n[0] <= n[1])
			cout << "Polycarp";
		else
			cout << "Vasiliy";	
	}	
	return 0;
}